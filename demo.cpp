#include"siliconboard.h"
#include<fstream>
#include<iostream>
#include <memory>
#include<time.h>

class DeriveImageControler :public Base_ImageContrler
{
public:
	DeriveImageControler(ImageCaptureBoard & img_cap_board, size_t port_index) :Base_ImageContrler(img_cap_board, port_index) {}
	void HowToProcessImages(void *img_prt, size_t picNr, size_t img_len) override
	{
		std::string filepath = "C:\\test\\pic";
		filepath += std::to_string(picNr) + std::string(".tiff");
		std::ofstream fout;
		fout.open(filepath.c_str(), std::ios::binary);
		if (fout.fail())
		{
			std::cout << "open file fail!" << std::endl;
		}
		char *p = (char *)img_prt;
		fout << p;
		fout.close();
		std::cout << "sucess output image " << picNr << std::endl;
	};
};
int main()
{
	
	SystemImageCaptureBoards sysboards;
	std::vector<ImageCaptureBoard> &v = sysboards.InitialSystemImageCaptureBoards();
	//一块板子
	if (v.size() == 1)
	{
		ImageCaptureBoard &board = v[0];
		board.RefreshPortConnectStatus();
		for (size_t i = 0; i < board.m_PortAmount; i++)
		{
			//测试设置参数 例子
			if (!board.m_CameraConnectStatus[i]) continue;
			CameraParameters para = board.GetCameraParameter(i);
			board.command_SetBase_2_10_bits(i);
			board.command_SetInternSynchro(i);
			board.command_SetExposure(i, 666);
			board.command_SetPositiveEdge(i);
			board.command_SetFrameRate(i,99);
			para = board.GetCameraParameter(i);
		}
		//由实际情况分配 相机控制器，相机对应采集卡上port： 0，A,1,B…… 
		std::vector<std::shared_ptr<Base_ImageContrler> > vv;
		for (size_t i = 0; i < board.m_CameraConnectStatus.size(); i++)
		{
			if (board.m_CameraConnectStatus[i])
			{
				vv.push_back(std::make_shared<DeriveImageControler>(board, i));
				vv[i]->Regist();
			}
			else
				vv.push_back(nullptr);
		}
		//以下为开始采相，2相机同时时为保持同步，不要用for，直接先后run，以下仅为样例
		for (auto item : vv)
		{
			if (item == nullptr) continue;
			clock_t start, finish;
			start = clock();
			item->Run_Acquire();
			while (1)
			{
				finish = clock();
				if ((start - finish) / CLOCKS_PER_SEC >= 10) break;
			}
			item->Stop_Acquire();
		}
	}
	return 0;
}