#include <iostream>
#include "AudioCaptureWorker.h"

void test()
{
	std::cout << "Heello" << std::endl;
}


int main()
{
	// Initialize audio capture worker
	FAudioCaptureWorker::Runnable->InitializeWorker();


	while (true)
	{
		FAudioCaptureWorker::Runnable->Run();
	}


	FAudioCaptureWorker::Runnable->ShutdownWorker();
	return 0;
}