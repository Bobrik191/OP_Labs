#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace op7;

[STAThread]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MyForm form; //WinFormsTest - имя вашего проекта
    Application::Run(% form);
}