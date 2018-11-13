#include "siliconboard.h"
size_t SystemImageCaptureBoards::DetectNrOfBoards()
{
	int nrOfBoards = 0;
	char buffer[256];
	unsigned int buflen = 256;
	buffer[0] = 0;

	// availability : starting with RT 5.2
	if (Fg_getSystemInformation(NULL, INFO_NR_OF_BOARDS, PROP_ID_VALUE, 0, buffer, &buflen) == FG_OK) {
		nrOfBoards = atoi(buffer);
	}
	this->m_BoardsAmount = nrOfBoards;
	return nrOfBoards;
}

void SystemImageCaptureBoards::DetectSystemImageCaptureBoardsInfo()
{
	m_VecOfImageCaptureBoard.clear();
	//detect board type
	for (size_t i = 0; i < this->m_BoardsAmount; i++)
	{
		int boardType = -1;
		int iPortNrOnBoard = 0;
		const char * boardName;
		boardType = Fg_getBoardType(i);
		switch (boardType)
		{
		case PN_MICROENABLE4AS1CL:
			boardName = "MicroEnable IV AS1-CL";
			iPortNrOnBoard = 1;
			break;
		case PN_MICROENABLE4AD1CL:
			boardName = "MicroEnable IV AD1-CL";
			iPortNrOnBoard = 1;
			break;
		case PN_MICROENABLE4VD1CL:
			boardName = "MicroEnable IV VD1-CL";
			iPortNrOnBoard = 2;
			break;
		case PN_MICROENABLE4AD4CL:
			boardName = "MicroEnable IV AD4-CL";
			iPortNrOnBoard = 2;
			break;
		case PN_MICROENABLE4VD4CL:
			boardName = "MicroEnable IV VD4-CL";
			iPortNrOnBoard = 2;
			break;
			// ignore the non-cameralink boards
		case PN_MICROENABLE3I:
		case PN_MICROENABLE3IXXL:
		case PN_MICROENABLE4AQ4GE:
		case PN_MICROENABLE4VQ4GE:
		default:
			boardName = "Unknown / Unsupported Board";
			break;
		}
		m_VecOfImageCaptureBoard.push_back(ImageCaptureBoard(boardName, boardType, iPortNrOnBoard, i ));
	}
}

void SystemImageCaptureBoards::InitialSystemImageCaptureBoards()
{
	//返回正常初始化的采集卡的数量
	DetectNrOfBoards();
	DetectSystemImageCaptureBoardsInfo();

	// board applete type pre-set (not apply yet)
	for (auto &item : m_VecOfImageCaptureBoard)
	{
		const char *applet;
		switch (item.m_enumBoardType)
		{
		case PN_MICROENABLE4AS1CL:
			applet = "SingleAreaGray16";
			break;
		case PN_MICROENABLE4AD1CL:
		case PN_MICROENABLE4AD4CL:
		case PN_MICROENABLE4VD1CL:
		case PN_MICROENABLE4VD4CL:
			applet = "DualAreaGray16";
			break;
		case PN_MICROENABLE4AQ4GE:
		case PN_MICROENABLE4VQ4GE:
			applet = "QuadAreaGray16";
			break;
		case PN_MICROENABLE3I:
			applet = "DualAreaGray";
			break;
		case PN_MICROENABLE3IXXL:
			applet = "DualAreaGray12XXL";
			break;
		default:
			applet = "DualAreaGray16";
			break;
		}
		item.m_Applete = applet;
	}

	//initial
	for (unsigned int i = 0; i < this->m_BoardsAmount; i++)
	{
		//初始化采集卡，并拿到Fb句柄
		m_VecOfImageCaptureBoard[i].m_FrameGraber_Ptr = Fg_Init(m_VecOfImageCaptureBoard[i].m_Applete.c_str(), m_VecOfImageCaptureBoard[i].m_BoardIndex);
		if (m_VecOfImageCaptureBoard[i].m_FrameGraber_Ptr == nullptr) 
			continue;
		//初始化端口
		int cnt = 0;
		for (size_t j = 0;j < this->m_VecOfImageCaptureBoard[i].m_PortAmount;j++)
		{
			void *p=NULL;
			if (clSerialInit(j, &p) == CL_ERR_NO_ERR)
			{
				this->m_VecOfImageCaptureBoard[i].m_serialRefPtr.push_back(p);
				cnt++;
			}
			else
			{
				this->m_VecOfImageCaptureBoard[i].m_serialRefPtr.push_back(NULL);
			}
		}
		if(cnt==this->m_VecOfImageCaptureBoard[i].m_PortAmount)
			m_VecOfImageCaptureBoard[i].m_IsInitialed = true;
	}
}

SystemImageCaptureBoards::~SystemImageCaptureBoards()
{
	for (auto item : m_VecOfImageCaptureBoard)
	{
		for (size_t i = 0; i < item.m_PortAmount; i++) {
			if (item.m_serialRefPtr[i] != nullptr)
			{
				clSerialClose(item.m_serialRefPtr[i]);
				item.m_serialRefPtr[i] = NULL;
			}
		}
		if (item.m_FrameGraber_Ptr != NULL)
		{
			Fg_FreeGrabber(item.m_FrameGraber_Ptr);
			item.m_FrameGraber_Ptr = NULL;
		}
	}

}

int ImageCaptureBoard::ReadData(size_t port_index, char *buf_to_save, size_t buf_length)
{
	//返回值：底层错误 -1，未初始化端口 -2 ,端口不存在 -3 ,正常：返回读取的byte数
	if (!m_IsInitialed) return -2;
	if (port_index >= this->m_PortAmount) return -3;
	size_t time_out = 500;
	if (clSerialRead(this->m_serialRefPtr[port_index], buf_to_save, &buf_length, time_out) == CL_ERR_NO_ERR)
		return buf_length;
	else return -1;
}

int ImageCaptureBoard::WriteData(size_t port_index, const char *buf_to_write, size_t buf_length)
{
	//返回值：底层错误 -1，未初始化端口 -2 ,端口不存在 -3 ,正常：返回写入的byte数
	if (!m_IsInitialed) return -2;
	if (port_index >= this->m_PortAmount) return -3;
	size_t time_out = 500;
	if (clSerialWrite(this->m_serialRefPtr[port_index], const_cast<char *>(buf_to_write), &buf_length, time_out) == CL_ERR_NO_ERR)
		return buf_length;
	else return -1;
}

void ImageCaptureBoard::ReadParameter(size_t port_index, std::string &buf_to_save)
{
	int len = 100;
	Sleep(50);
	do {
		char tmpRet[512];
		len = ReadData(port_index, tmpRet, sizeof(tmpRet));
		if (len >= 0) {
			buf_to_save += std::string(tmpRet, len);
			Sleep(35);
		}
	} while (len > 0);
}

bool ImageCaptureBoard::WriteParameter(size_t port_index, const std::string &buf_to_write)
{
	Sleep(100);
	if (WriteData(port_index, &buf_to_write[0], buf_to_write.size()) > 0)
	{
		return true;
	}
	else return false;
}

int ImageCaptureBoard::RefreshPortConnectStatus()
{
	//检测有几个相机连接上，结果存在m_CameraConnectStatus中,若检测到相机
	//错误代码：0：0个相机已接上，-1：采集卡未初始化
	//返回 已连接 的的相机个数
	if (!m_IsInitialed) return -1;
	m_CameraConnectStatus.clear();
	int cnt = 0;
	//相机连接状态
	for (size_t i = 0; i < this->m_PortAmount; i++)
	{
		int camStatus = 0;
		Fg_getParameter(m_FrameGraber_Ptr, FG_CAMSTATUS, &camStatus, i);
		if (camStatus == 0)
		{
			m_CameraConnectStatus.push_back(false);
		}
		else
		{
			cnt++;
			m_CameraConnectStatus.push_back(true);
		}
	}
	return cnt;
}

std::vector<std::string> ImageCaptureBoard::split(const std::string& str, const std::string& delim)
{
	using std::vector;
	using std::string;
	vector<string> res;
	if ("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型
	char * strs = new char[str.length() + 1]; //不要忘了
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	while (p) {
		string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果数组
		p = strtok(NULL, d);
	}
	delete[]strs;
	return res;
}

CameraParameters ImageCaptureBoard::GetCameraParameter(size_t port_index)
{
	using std::vector;
	using std::string;
	CameraParameters result;
	//刷新当前相机状态
	RefreshPortConnectStatus();
	if (!m_CameraConnectStatus[port_index]) return result;
	//获取全部参数并预处理
	WriteParameter(port_index, std::string("#X\r"));
	std::string read_tmp;
	ReadParameter(port_index, read_tmp);
	read_tmp = std::regex_replace(read_tmp, std::regex("[^0-9\r\n,]"), std::string(""));
	vector<string> split_tmp = split(read_tmp, string("\r\n"));
	if (split_tmp.size() < 18) return result;
	// m_ImageWidth + m_ImageHeight;
	vector<string> vec_tmp_wh = split(split_tmp[3], string(","));
	result.m_ImageWidth = vec_tmp_wh[0];
	result.m_ImageHeight = vec_tmp_wh[1];
	// m_ImageRate;
	result.m_FrameFrequency = split_tmp[6];
	// m_ExposureTime;
	result.m_ExposureTime = split_tmp[7];
	// m_Synchro;
	if (split_tmp[14][0] == '0')
	{
		result.m_Synchro = '0';
	}
	else if (split_tmp[14][0] == '1')
	{
		result.m_Synchro = '1';
	}
	// m_Polarity;
	string polar_tmp = split_tmp[16] + split_tmp[15];
	if (polar_tmp == "00")
	{	//Negative Level
		result.m_Polarity = "00";
	}
	else if (polar_tmp == "01")
	{	//Negative Edge
		result.m_Polarity = "01";
	}
	else if (polar_tmp == "10")
	{	//Positive Level
		result.m_Polarity = "10";
	}
	else if (polar_tmp == "11")
	{	//Positive Edge
		result.m_Polarity = "11";
	}
	// m_CLMode;
	int syn_size = split_tmp[0].length();
	if (split_tmp[0][syn_size - 1] == '0')
	{	//2x8 bits
		result.m_CLMode = '0';
	}
	else if (split_tmp[0][syn_size - 1] == '1')
	{	//2x10 bits
		result.m_CLMode = '1';
	}
	//m_CameraLinkFrequency
	WriteParameter(port_index, string("#c\r"));
	string CameraLinkFrequency_tmp;
	ReadParameter(port_index, CameraLinkFrequency_tmp);
	CameraLinkFrequency_tmp = std::regex_replace(CameraLinkFrequency_tmp, std::regex("[^0-9]"), std::string(""));
	if (CameraLinkFrequency_tmp == "0")
	{	//66
		result.m_CameraLinkFrequency = "0";
	}
	else if (CameraLinkFrequency_tmp == "1")
	{	//75
		result.m_CameraLinkFrequency = "1";
	}
	else if (CameraLinkFrequency_tmp == "2")
	{	//85
		result.m_CameraLinkFrequency = "2";
	}
	return result;
}

CameraMaxExposureTime_MaxFPS ImageCaptureBoard::GetCameraMaxExposureTime_MaxFPS(size_t port_index)
{
	using std::vector;
	using std::string;
	CameraMaxExposureTime_MaxFPS result;
	//刷新当前相机状态
	RefreshPortConnectStatus();
	if (!m_CameraConnectStatus[port_index]) return result;
	//m_ImageMaxRate + m_ImageMaxExposureTime
	WriteParameter(port_index, string("#A\r"));
	WriteParameter(port_index, string("#a\r"));

	string MaxRate_Expo_tmp;
	ReadParameter(port_index, MaxRate_Expo_tmp);
	MaxRate_Expo_tmp = std::regex_replace(MaxRate_Expo_tmp, std::regex("[^0-9\r\n,]"), std::string(""));
	vector<string> split_tmp = split(MaxRate_Expo_tmp, string("\r\n"));
	for (size_t i = 0; i < split_tmp.size(); ++i) {
		if (split_tmp[i] == "") {
			split_tmp.erase(split_tmp.begin() + i);
			--i;
		}
	}
	if (split_tmp.size() < 2) return result;
	// m_ImageMaxRate;
	result.m_ImageMaxRate = split_tmp[0];
	// m_ImageMaxExposureTime;
	result.m_ImageMaxExposureTime = split_tmp[1];
	return result;
}

bool ImageCaptureBoard::command_SetBase_2_8_bits(size_t port_index)
{
	return WriteParameter(port_index, std::string("#C(0)\r"));
}

bool ImageCaptureBoard::command_SetBase_2_10_bits(size_t port_index)
{
	return WriteParameter(port_index, std::string("#C(1)\r"));
}

bool ImageCaptureBoard::command_SetExternSynchro(size_t port_index)
{
	return WriteParameter(port_index, std::string("#S(1)\r"));
}

bool ImageCaptureBoard::command_SetInternSynchro(size_t port_index)
{
	return WriteParameter(port_index, std::string("#S(0)\r"));
}

bool ImageCaptureBoard::command_SetPositiveEdge(size_t port_index)
{	if (WriteParameter(port_index, std::string("#P(1)\r")) && WriteParameter(port_index, std::string("#m(1)\r")))
		return true;
	else return false;
}

bool ImageCaptureBoard::command_SetPositiveLevel(size_t port_index)
{
	if (WriteParameter(port_index, std::string("#P(1)\r")) && WriteParameter(port_index, std::string("#m(0)\r")))
		return true;
	else return false;
}

bool ImageCaptureBoard::command_SetNegativeEdge(size_t port_index)
{
	if (WriteParameter(port_index, std::string("#P(0)\r")) && WriteParameter(port_index, std::string("#m(1)\r")))
		return true;
	else return false;
}

bool ImageCaptureBoard::command_SetNegativeLevel(size_t port_index)
{
	if (WriteParameter(port_index, std::string("#P(0)\r")) && WriteParameter(port_index, std::string("#m(0)\r")))
		return true;
	else return false;
}

bool ImageCaptureBoard::command_SetFrameFormat(size_t port_index, size_t img_width, size_t img_height)
{
	std::string text_tmp = std::string("#R(") + std::to_string(img_width) + std::string(",") + std::to_string(img_height) + std::string(")\r");
	return WriteParameter(port_index, text_tmp);
}

bool ImageCaptureBoard::command_SetExposure(size_t port_index, size_t exposure)
{
	std::string text_tmp = std::string("#e(") + std::to_string(exposure) + std::string(")\r");
	return WriteParameter(port_index, text_tmp);
}

bool ImageCaptureBoard::command_SetFrameRate(size_t port_index, size_t frame_rate)
{
	std::string text_tmp = std::string("#r(") + std::to_string(frame_rate) + std::string(")\r");
	return WriteParameter(port_index, text_tmp);
}

bool ImageCaptureBoard::command_SetCameraLinkFrequency(size_t port_index, size_t frequency)
{
	std::string text_tmp = std::string("#c(") + std::to_string(frequency) + std::string(")\r");
	return WriteParameter(port_index, text_tmp);
} 

CameraParameters Base_ImageContrler::SetCameraParameter(const CameraParameters& para)
{
	//clmode
	if (para.m_CLMode != m_CameraParameters.m_CLMode)
	{
		if (para.m_CLMode == std::string("0"))
		{
			m_ImgCaptureBoard_ptr->command_SetBase_2_8_bits(m_apc_data.dmaIndex);
		}
		else if (para.m_CLMode == std::string("1"))
		{
			m_ImgCaptureBoard_ptr->command_SetBase_2_10_bits(m_apc_data.dmaIndex);
		}
	}
	//Synchro
	if (para.m_Synchro != m_CameraParameters.m_Synchro)
	{
		if (para.m_Synchro == std::string("0"))
		{
			m_ImgCaptureBoard_ptr->command_SetInternSynchro(m_apc_data.dmaIndex);
		}
		else if (para.m_Synchro == std::string("1"))
		{
			m_ImgCaptureBoard_ptr->command_SetExternSynchro(m_apc_data.dmaIndex);
		}
	}
	//Polarity
	if (para.m_Polarity != m_CameraParameters.m_Polarity)
	{
		if (para.m_Polarity == std::string("00"))
		{
			m_ImgCaptureBoard_ptr->command_SetNegativeLevel(m_apc_data.dmaIndex);
		}
		else if (para.m_Polarity == std::string("01"))
		{
			m_ImgCaptureBoard_ptr->command_SetNegativeEdge(m_apc_data.dmaIndex);
		}
		else if (para.m_Polarity == std::string("10"))
		{
			m_ImgCaptureBoard_ptr->command_SetPositiveLevel(m_apc_data.dmaIndex);
		}
		else if (para.m_Polarity == std::string("11"))
		{
			m_ImgCaptureBoard_ptr->command_SetPositiveEdge(m_apc_data.dmaIndex);
		}
	}
	//FrameFormat
	if (para.m_ImageHeight != m_CameraParameters.m_ImageHeight || para.m_ImageWidth != m_CameraParameters.m_ImageWidth)
	{
		m_ImgCaptureBoard_ptr->command_SetFrameFormat(m_apc_data.dmaIndex, std::atoi(para.m_ImageWidth.c_str()), std::atoi(para.m_ImageHeight.c_str()));
	}
	//Exposure
	if (para.m_ExposureTime != m_CameraParameters.m_ExposureTime)
	{
		m_ImgCaptureBoard_ptr->command_SetExposure(m_apc_data.dmaIndex, std::atoi(para.m_ExposureTime.c_str()));
	}
	//FrameRate
	if (para.m_FrameFrequency != m_CameraParameters.m_FrameFrequency)
	{
		m_ImgCaptureBoard_ptr->command_SetFrameRate(m_apc_data.dmaIndex, std::atoi(para.m_FrameFrequency.c_str()));
	}
	//CameraLinkFrequency
	if (para.m_CameraLinkFrequency != m_CameraParameters.m_CameraLinkFrequency)
	{
		m_ImgCaptureBoard_ptr->command_SetCameraLinkFrequency(m_apc_data.dmaIndex, std::atoi(para.m_CameraLinkFrequency.c_str()));
	}
	Sleep(100);
	m_CameraParameters = m_ImgCaptureBoard_ptr->GetCameraParameter(m_apc_data.dmaIndex);
	FreshCameraParametersToImageCaptureBoard();
	return m_CameraParameters;
}

void Base_ImageContrler::FreshCameraParametersToImageCaptureBoard()
{
	int camera_link_type_ = 108;
	int triggermode = GRABBER_CONTROLLED;
	Fg_setParameter(m_apc_data.fg, FG_TRIGGERMODE, &triggermode, m_apc_data.dmaIndex);
	auto width_ = atoi(m_CameraParameters.m_ImageWidth.c_str());
	auto heigh_ = atoi(m_CameraParameters.m_ImageHeight.c_str());
	auto expo_ = atoi(m_CameraParameters.m_ExposureTime.c_str());
	auto fps_ = atoi(m_CameraParameters.m_FrameFrequency.c_str());

	auto a=Fg_setParameter(m_apc_data.fg, FG_WIDTH, &width_, m_apc_data.dmaIndex);
	auto b=Fg_setParameter(m_apc_data.fg, FG_HEIGHT, &heigh_, m_apc_data.dmaIndex);
	auto c=Fg_setParameter(m_apc_data.fg, FG_EXPOSURE, &expo_, m_apc_data.dmaIndex);
	auto d=Fg_setParameter(m_apc_data.fg, FG_FRAMESPERSEC, &fps_, m_apc_data.dmaIndex);
	auto e=Fg_setParameter(m_apc_data.fg, FG_CAMERA_LINK_CAMTYP, &camera_link_type_, m_apc_data.dmaIndex);
}

Base_ImageContrler::Base_ImageContrler(ImageCaptureBoard &img_cap_board, size_t port_index)
{
	m_BufferAmount = 128;
	m_Is_registered = false;
	m_ImageFormat = 0;
	m_BytesPerPixel = 0;
	m_ImgCaptureBoard_ptr = &img_cap_board;
	m_apc_data.dmaIndex = port_index;
	m_apc_data.fg = img_cap_board.m_FrameGraber_Ptr;
	m_apc_data.mem = nullptr;
	m_apc_data.m_ImageContrler = this;
	m_CameraParameters = img_cap_board.GetCameraParameter(port_index);
	m_MaxExposure_FPS = img_cap_board.GetCameraMaxExposureTime_MaxFPS(port_index);
}

Base_ImageContrler::~Base_ImageContrler()
{
	if (m_Is_registered) {
		Fg_registerApcHandler(m_apc_data.fg, m_apc_data.dmaIndex, NULL, FG_APC_CONTROL_BASIC);
		m_Is_registered = false;
	}
	if (m_apc_data.mem != nullptr) {
		Fg_FreeMemEx(m_apc_data.fg, m_apc_data.mem);
		m_apc_data.mem = nullptr;
	}
}

int Base_ImageContrler::Regist()
{
	//返回状态说明：1：正常  -1:申请内存失败 -2:注册失败  
	if (!m_Is_registered)
	{
		Fg_getParameter(m_apc_data.fg, FG_FORMAT, &m_ImageFormat, m_apc_data.dmaIndex);
		switch (m_ImageFormat)
		{
		case FG_GRAY:	m_BytesPerPixel = 1; break;
		case FG_GRAY16:	m_BytesPerPixel = 2; break;
		case FG_COL24:	m_BytesPerPixel = 3; break;
		case FG_COL32:	m_BytesPerPixel = 4; break;
		case FG_COL30:	m_BytesPerPixel = 5; break;
		case FG_COL48:	m_BytesPerPixel = 6; break;
		}
		// Memory allocation
		//释放上一次残留内存
		if (m_apc_data.mem != nullptr) {
			Fg_FreeMemEx(m_apc_data.fg, m_apc_data.mem);
			m_apc_data.mem = nullptr;
		}
		//分配新内存
		size_t totalBufSize = std::atoi(m_CameraParameters.m_ImageWidth.c_str()) 
							* std::atoi(m_CameraParameters.m_ImageHeight.c_str())  * m_BufferAmount * m_BytesPerPixel;
		dma_mem *pMem = Fg_AllocMemEx(m_apc_data.fg, totalBufSize, m_BufferAmount);
		if (pMem == nullptr) return -1;
		m_apc_data.mem = pMem;
		//regist
		struct FgApcControl ctrl;
		ctrl.version = 0;
		ctrl.data = &m_apc_data;
		ctrl.flags = FG_APC_DEFAULTS;
		ctrl.timeout = 10;
		ctrl.func = CallBackFunc;
		if (Fg_registerApcHandler(m_apc_data.fg, m_apc_data.dmaIndex, &ctrl, FG_APC_CONTROL_BASIC) != FG_OK)
		{
			return -2;
		}
		m_Is_registered = true;
	}
	return 1;
}

int Base_ImageContrler::Run_Acquire(size_t acquire_count)
{
	//返回状态说明：1：正常  -1:未注册  -3:Acquire失败 
	//acquire_count:捕获的张数，默认为0(即连续捕捉)
	if (!m_Is_registered) return -1;
	if (acquire_count == 0)
	{
		if (Fg_AcquireEx(m_apc_data.fg, m_apc_data.dmaIndex, GRAB_INFINITE, ACQ_STANDARD, m_apc_data.mem) <0)
		{
			return -3;
		}
	}
	else
	{
		if ((Fg_AcquireEx(m_apc_data.fg, m_apc_data.dmaIndex, acquire_count, ACQ_STANDARD, m_apc_data.mem)) < 0)
		{
			return -3;
		}
	}
	return 1;
}

void Base_ImageContrler::Stop_Acquire()
{
	Fg_stopAcquireEx(m_apc_data.fg, m_apc_data.dmaIndex, m_apc_data.mem, 0);

	if (m_Is_registered) {
		Fg_registerApcHandler(m_apc_data.fg, m_apc_data.dmaIndex, NULL, FG_APC_CONTROL_BASIC);
		m_Is_registered = false;
	}
	//内存释放 放在Regist内管理
}

extern "C" int CallBackFunc(frameindex_t picNr, fg_apc_data *apcdata)
{
	void *data = Fg_getImagePtrEx(apcdata->fg, picNr, apcdata->dmaIndex, apcdata->mem);
	size_t img_len=0;
	//Fg_getParameterEx(apcdata->fg, FG_TRANSFER_LEN, &img_len, apcdata->dmaIndex, apcdata->mem, picNr);
	apcdata->m_ImageContrler->HowToProcessImages(data, img_len);
	return 0;
}
