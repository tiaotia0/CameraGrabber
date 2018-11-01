#ifndef SILICONBOARD_H
#define SILICONBOARD_H

#define _CRT_SECURE_NO_WARNINGS
#include <fgrab_struct.h>
#include <fgrab_prototyp.h>
#include <fgrab_define.h>
#include <SisoDisplay.h>
#include <clser.h>
#include <vector>
#include <string>
#include <regex>

struct CameraParameters
{
	std::string m_ImageWidth;
	std::string m_ImageHeight;
	std::string m_ImageMaxRate;
	std::string m_ImageMaxExposureTime;
	std::string m_ImageRate;
	std::string m_ExposureTime;
	std::string m_Synchro;
	std::string m_Polarity;
	std::string m_CLMode;
	std::string m_CameraLinkFrequency;
};

class Base_ImageContrler;
struct fg_apc_data 
{
	Fg_Struct *fg;
	unsigned int dmaIndex;
	dma_mem *mem;
	Base_ImageContrler *m_ImageContrler;
	fg_apc_data() :fg(nullptr), dmaIndex(-1), mem(nullptr), m_ImageContrler(nullptr) {}
};

class ImageCaptureBoard
{
public:
    ImageCaptureBoard() :m_BoardName(""), m_enumBoardType(-1), m_PortAmount(0), m_Applete("") {}
	ImageCaptureBoard(const std::string &board_name, size_t board_type, size_t port_amount, size_t board_index ,const std::string &applete="")
                        :m_BoardName(board_name), m_enumBoardType(board_type), m_PortAmount(port_amount),m_BoardIndex(board_index),m_Applete(applete) {}

	std::string m_BoardName;
	std::string m_Applete;
	size_t m_enumBoardType;
	size_t m_PortAmount;
	size_t m_BoardIndex ;
	std::vector<void*> m_serialRefPtr;   //指向端口的指针数组
	Fg_Struct *m_FrameGraber_Ptr = NULL;
	bool m_IsInitialed = false;
	std::vector<bool> m_CameraConnectStatus;

	int ReadData(size_t port_index, char *buf_to_save, size_t buf_length);
	int WriteData(size_t port_index,const char *buf_to_write, size_t buf_length);
	void ReadParameter(size_t port_index, std::string &buf_to_save);
	bool WriteParameter(size_t port_index, const std::string &buf_to_write);
	int RefreshPortConnectStatus(); 

	CameraParameters GetCameraParameter(size_t port_index);
	bool command_SetBase_2_8_bits(size_t port_index);
	bool command_SetBase_2_10_bits(size_t port_index);
	bool command_SetExternSynchro(size_t port_index);
	bool command_SetInternSynchro(size_t port_index);
	bool command_SetPositiveEdge(size_t port_index);
	bool command_SetPositiveLevel(size_t port_index);
	bool command_SetNegativeEdge(size_t port_index);
	bool command_SetNegativeLevel(size_t port_index);
	bool command_SetFrameFormat(size_t port_index, size_t img_width, size_t img_height);
	bool command_SetExposure(size_t port_index, size_t exposure);
	bool command_SetFrameRate(size_t port_index, size_t frame_rate);
	bool command_SetCameraLinkFrequency(size_t port_index, size_t frequency);
};

class SystemImageCaptureBoards
{
public:
    SystemImageCaptureBoards() :m_BoardsAmount(0) {}
	~SystemImageCaptureBoards();

	size_t m_BoardsAmount;
	std::vector<ImageCaptureBoard> m_VecOfImageCaptureBoard;

	size_t DetectNrOfBoards();
	void DetectSystemImageCaptureBoardsInfo();
	std::vector<ImageCaptureBoard>& InitialSystemImageCaptureBoards();
};

class Base_ImageContrler
{
	//必须继承后使用
public:
	int m_bytesPerPixel;
	size_t m_ImageWidth;
	size_t m_ImageHeight;
	size_t m_BufferAmount;
	size_t m_FramFrequency;
	bool m_Is_registered;
	fg_apc_data m_apc_data;

	virtual void HowToProcessImages(void *img_prt, size_t picNr, size_t img_len) = 0;
	int Regist();
	int Run_Acquire(size_t acquire_count=0);
	int Pause_Acquire();
	void Stop_Acquire();

	Base_ImageContrler(ImageCaptureBoard &img_cap_board, size_t port_index);
	~Base_ImageContrler();
};

extern "C" int CallBackFunc(frameindex_t picNr, fg_apc_data *apcdata);
#endif // SILICONBOARD_H
