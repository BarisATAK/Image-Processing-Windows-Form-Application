#include "ImagesProcessing.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ImageProcessForm::ImagesProcessing form;
	Application::Run(%form);
	
}
