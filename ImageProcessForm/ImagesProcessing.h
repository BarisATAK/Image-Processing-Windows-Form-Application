#pragma once
#include <Windows.h>
#include "Imaging.h"
#include "atlstr.h"

#define x1 50
#define y1 50
#define x4 200
#define y4 200

namespace ImageProcessForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ImagesProcessing
	/// </summary>
	public ref class ImagesProcessing : public System::Windows::Forms::Form
	{
	public:
		ImagesProcessing(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ImagesProcessing()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:

	protected:

	protected:





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int Width, Height;
		long Size, new_size;


	private: System::Windows::Forms::Panel^  panel1;



	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  hist;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  k_means_histogram;
	private: System::Windows::Forms::Button^  save_button;



	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  d_line;
	private: System::Windows::Forms::Button^  conv;
	private: System::Windows::Forms::OpenFileDialog^  draw_line_dialog;


	private: System::Windows::Forms::OpenFileDialog^  convolution_dialog;


	private: System::Windows::Forms::OpenFileDialog^  k_means_dialog;
	private: System::Windows::Forms::Button^  k_means;
	private: System::Windows::Forms::Button ^ not;





	private: System::Windows::Forms::OpenFileDialog^  notDialog;
	private: System::Windows::Forms::Button^  reverse_button;
	private: System::Windows::Forms::OpenFileDialog^  reverseDialog;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  erosion_click;

	private: System::Windows::Forms::Button^  dilation_click;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;




	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			this->k_means_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->save_button = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->hist = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->k_means_histogram = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->draw_line_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->erosion_click = (gcnew System::Windows::Forms::Button());
			this->dilation_click = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->reverse_button = (gcnew System::Windows::Forms::Button());
			this->not = (gcnew System::Windows::Forms::Button());
			this->k_means = (gcnew System::Windows::Forms::Button());
			this->conv = (gcnew System::Windows::Forms::Button());
			this->d_line = (gcnew System::Windows::Forms::Button());
			this->convolution_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->notDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->reverseDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hist))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->k_means_histogram))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// k_means_dialog
			// 
			this->k_means_dialog->FileName = L"k_means_dialog";
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::DarkSlateGray;
			this->panel1->Controls->Add(this->save_button);
			this->panel1->Location = System::Drawing::Point(1578, -2);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(136, 826);
			this->panel1->TabIndex = 5;
			// 
			// save_button
			// 
			this->save_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->save_button->Enabled = false;
			this->save_button->Font = (gcnew System::Drawing::Font(L"Arial Black", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->save_button->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->save_button->Location = System::Drawing::Point(0, 118);
			this->save_button->Margin = System::Windows::Forms::Padding(4);
			this->save_button->Name = L"save_button";
			this->save_button->Size = System::Drawing::Size(136, 48);
			this->save_button->TabIndex = 4;
			this->save_button->Text = L"Save";
			this->save_button->UseVisualStyleBackColor = false;
			this->save_button->Click += gcnew System::EventHandler(this, &ImagesProcessing::save_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->Location = System::Drawing::Point(242, 390);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(347, 295);
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &ImagesProcessing::pictureBox4_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Location = System::Drawing::Point(242, 56);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(347, 295);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &ImagesProcessing::pictureBox1_Click);
			// 
			// hist
			// 
			this->hist->BackColor = System::Drawing::Color::WhiteSmoke;
			this->hist->BackImageTransparentColor = System::Drawing::Color::WhiteSmoke;
			this->hist->BackSecondaryColor = System::Drawing::Color::WhiteSmoke;
			this->hist->BorderlineColor = System::Drawing::Color::WhiteSmoke;
			chartArea1->BackColor = System::Drawing::Color::WhiteSmoke;
			chartArea1->BackSecondaryColor = System::Drawing::Color::DimGray;
			chartArea1->BorderColor = System::Drawing::Color::DimGray;
			chartArea1->Name = L"ChartArea1";
			chartArea1->ShadowColor = System::Drawing::Color::Gray;
			this->hist->ChartAreas->Add(chartArea1);
			legend1->BackColor = System::Drawing::Color::WhiteSmoke;
			legend1->BackSecondaryColor = System::Drawing::Color::Transparent;
			legend1->BorderColor = System::Drawing::Color::Transparent;
			legend1->ForeColor = System::Drawing::Color::Gray;
			legend1->HeaderSeparatorColor = System::Drawing::Color::Transparent;
			legend1->ItemColumnSeparatorColor = System::Drawing::Color::Transparent;
			legend1->Name = L"Legend1";
			legend1->ShadowColor = System::Drawing::Color::Transparent;
			legend1->TitleForeColor = System::Drawing::Color::Transparent;
			legend1->TitleSeparatorColor = System::Drawing::Color::Transparent;
			this->hist->Legends->Add(legend1);
			this->hist->Location = System::Drawing::Point(714, 56);
			this->hist->Name = L"hist";
			this->hist->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
			this->hist->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->hist->Size = System::Drawing::Size(671, 328);
			this->hist->TabIndex = 8;
			this->hist->Text = L"chart1";
			this->hist->Click += gcnew System::EventHandler(this, &ImagesProcessing::chart1_Click);
			// 
			// k_means_histogram
			// 
			this->k_means_histogram->BackColor = System::Drawing::Color::WhiteSmoke;
			this->k_means_histogram->BackImageTransparentColor = System::Drawing::Color::WhiteSmoke;
			this->k_means_histogram->BackSecondaryColor = System::Drawing::Color::WhiteSmoke;
			this->k_means_histogram->BorderlineColor = System::Drawing::Color::WhiteSmoke;
			chartArea2->BackColor = System::Drawing::Color::WhiteSmoke;
			chartArea2->BackSecondaryColor = System::Drawing::Color::DimGray;
			chartArea2->BorderColor = System::Drawing::Color::DimGray;
			chartArea2->Name = L"ChartArea1";
			chartArea2->ShadowColor = System::Drawing::Color::Gray;
			this->k_means_histogram->ChartAreas->Add(chartArea2);
			legend2->BackColor = System::Drawing::Color::WhiteSmoke;
			legend2->BackSecondaryColor = System::Drawing::Color::Transparent;
			legend2->BorderColor = System::Drawing::Color::Transparent;
			legend2->ForeColor = System::Drawing::Color::Gray;
			legend2->HeaderSeparatorColor = System::Drawing::Color::Transparent;
			legend2->ItemColumnSeparatorColor = System::Drawing::Color::Transparent;
			legend2->Name = L"Legend1";
			legend2->ShadowColor = System::Drawing::Color::Transparent;
			legend2->TitleForeColor = System::Drawing::Color::Transparent;
			legend2->TitleSeparatorColor = System::Drawing::Color::Transparent;
			this->k_means_histogram->Legends->Add(legend2);
			this->k_means_histogram->Location = System::Drawing::Point(714, 390);
			this->k_means_histogram->Name = L"k_means_histogram";
			this->k_means_histogram->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
			this->k_means_histogram->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->k_means_histogram->Size = System::Drawing::Size(671, 328);
			this->k_means_histogram->TabIndex = 9;
			this->k_means_histogram->Text = L"chart1";
			this->k_means_histogram->Click += gcnew System::EventHandler(this, &ImagesProcessing::k_means_histogram_Click);
			// 
			// draw_line_dialog
			// 
			this->draw_line_dialog->FileName = L"draw_line_dialog";
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel2->BackColor = System::Drawing::Color::DarkSlateGray;
			this->panel2->Controls->Add(this->erosion_click);
			this->panel2->Controls->Add(this->dilation_click);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->reverse_button);
			this->panel2->Controls->Add(this->not);
			this->panel2->Controls->Add(this->k_means);
			this->panel2->Controls->Add(this->conv);
			this->panel2->Controls->Add(this->d_line);
			this->panel2->Location = System::Drawing::Point(0, -2);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(135, 826);
			this->panel2->TabIndex = 10;
			// 
			// erosion_click
			// 
			this->erosion_click->BackColor = System::Drawing::Color::WhiteSmoke;
			this->erosion_click->Font = (gcnew System::Drawing::Font(L"Arial Black", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->erosion_click->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->erosion_click->Location = System::Drawing::Point(0, 529);
			this->erosion_click->Margin = System::Windows::Forms::Padding(4);
			this->erosion_click->Name = L"erosion_click";
			this->erosion_click->Size = System::Drawing::Size(135, 48);
			this->erosion_click->TabIndex = 12;
			this->erosion_click->Text = L"Erosion";
			this->erosion_click->UseVisualStyleBackColor = false;
			this->erosion_click->Click += gcnew System::EventHandler(this, &ImagesProcessing::erosion_click_Click);
			// 
			// dilation_click
			// 
			this->dilation_click->BackColor = System::Drawing::Color::WhiteSmoke;
			this->dilation_click->Font = (gcnew System::Drawing::Font(L"Arial Black", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dilation_click->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->dilation_click->Location = System::Drawing::Point(0, 473);
			this->dilation_click->Margin = System::Windows::Forms::Padding(4);
			this->dilation_click->Name = L"dilation_click";
			this->dilation_click->Size = System::Drawing::Size(135, 48);
			this->dilation_click->TabIndex = 11;
			this->dilation_click->Text = L"Dilation";
			this->dilation_click->UseVisualStyleBackColor = false;
			this->dilation_click->Click += gcnew System::EventHandler(this, &ImagesProcessing::dilation_click_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Black", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->Location = System::Drawing::Point(0, 286);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(135, 48);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Zoom";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &ImagesProcessing::zoom_click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Black", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Location = System::Drawing::Point(0, 585);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 67);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Bounding Box";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ImagesProcessing::bounding_box_click);
			// 
			// reverse_button
			// 
			this->reverse_button->BackColor = System::Drawing::Color::WhiteSmoke;
			this->reverse_button->Font = (gcnew System::Drawing::Font(L"Arial Black", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reverse_button->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->reverse_button->Location = System::Drawing::Point(0, 230);
			this->reverse_button->Margin = System::Windows::Forms::Padding(4);
			this->reverse_button->Name = L"reverse_button";
			this->reverse_button->Size = System::Drawing::Size(135, 48);
			this->reverse_button->TabIndex = 8;
			this->reverse_button->Text = L"Reverse";
			this->reverse_button->UseVisualStyleBackColor = false;
			this->reverse_button->Click += gcnew System::EventHandler(this, &ImagesProcessing::reverse_button_Click);
			// 
			// not
			// 
			this->not->BackColor = System::Drawing::Color::WhiteSmoke;
			this->not->Font = (gcnew System::Drawing::Font(L"Arial Black", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->not->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->not->Location = System::Drawing::Point(0, 174);
			this->not->Margin = System::Windows::Forms::Padding(4);
			this->not->Name = L"not";
			this->not->Size = System::Drawing::Size(135, 48);
			this->not->TabIndex = 7;
			this->not->Text = L"Not";
			this->not->UseVisualStyleBackColor = false;
			this->not->Click += gcnew System::EventHandler(this, &ImagesProcessing::Not_Click);
			// 
			// k_means
			// 
			this->k_means->BackColor = System::Drawing::Color::WhiteSmoke;
			this->k_means->Font = (gcnew System::Drawing::Font(L"Arial Black", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->k_means->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->k_means->Location = System::Drawing::Point(0, 398);
			this->k_means->Margin = System::Windows::Forms::Padding(4);
			this->k_means->Name = L"k_means";
			this->k_means->Size = System::Drawing::Size(135, 67);
			this->k_means->TabIndex = 6;
			this->k_means->Text = L"K-Means Clustering";
			this->k_means->UseVisualStyleBackColor = false;
			this->k_means->Click += gcnew System::EventHandler(this, &ImagesProcessing::k_means_Click);
			// 
			// conv
			// 
			this->conv->BackColor = System::Drawing::Color::WhiteSmoke;
			this->conv->Font = (gcnew System::Drawing::Font(L"Arial Black", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->conv->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->conv->Location = System::Drawing::Point(0, 342);
			this->conv->Margin = System::Windows::Forms::Padding(4);
			this->conv->Name = L"conv";
			this->conv->Size = System::Drawing::Size(135, 48);
			this->conv->TabIndex = 5;
			this->conv->Text = L"Convolution";
			this->conv->UseVisualStyleBackColor = false;
			this->conv->Click += gcnew System::EventHandler(this, &ImagesProcessing::conv_Click);
			// 
			// d_line
			// 
			this->d_line->BackColor = System::Drawing::Color::WhiteSmoke;
			this->d_line->Font = (gcnew System::Drawing::Font(L"Arial Black", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->d_line->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->d_line->Location = System::Drawing::Point(0, 118);
			this->d_line->Margin = System::Windows::Forms::Padding(4);
			this->d_line->Name = L"d_line";
			this->d_line->Size = System::Drawing::Size(135, 48);
			this->d_line->TabIndex = 4;
			this->d_line->Text = L"Draw Line";
			this->d_line->UseVisualStyleBackColor = false;
			this->d_line->Click += gcnew System::EventHandler(this, &ImagesProcessing::draw_line_Click);
			// 
			// convolution_dialog
			// 
			this->convolution_dialog->FileName = L"convolution_dialog";
			// 
			// notDialog
			// 
			this->notDialog->FileName = L"notDialog";
			// 
			// reverseDialog
			// 
			this->reverseDialog->FileName = L"reverseDialog";
			// 
			// ImagesProcessing
			// 
			this->AccessibleDescription = L"";
			this->AccessibleName = L"aaaa";
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(1713, 816);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->k_means_histogram);
			this->Controls->Add(this->hist);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Algerian", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"ImagesProcessing";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Tag = L"";
			this->Text = L"Image Processing Form";
			this->TransparencyKey = System::Drawing::Color::LightPink;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &ImagesProcessing::ImagesProcessing_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hist))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->k_means_histogram))->EndInit();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}

private: System::Void ImagesProcessing_Load(System::Object^  sender, System::EventArgs^  e) {
}
	private: System::Void save_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveFileDialog^ sfd = gcnew SaveFileDialog();
		sfd->Filter = "Images|*.bmp";
		System::Drawing::Imaging::ImageFormat^ format;
		if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox4->Image->Save(sfd->FileName, format->Bmp);
			if (sfd->FileName != "")
				MessageBox::Show("Image is saved.");
		}
	}
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void pictureBox3_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void k_means_histogram_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void draw_line_Click(System::Object^  sender, System::EventArgs^  e) {
	LPCTSTR input;
	CString str;

	k_means_histogram->Series->Clear();
	hist->Series->Clear();
	hist->Series->Add("Pixel Count");

	if (draw_line_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		str = draw_line_dialog->FileName;
		input = (LPCTSTR)str;
		if (input != NULL)
			save_button->Enabled = true;
	}
	
	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

	pictureBox1->Width = Width;
	pictureBox1->Height = Height;

	pictureBox4->Width = Width;
	pictureBox4->Height = Height;

	int* histogram = Histogram(raw_intensity, Width, Height);
	BYTE* draw_line = Draw_Line(raw_intensity, Width, Height, x1, y1, x4, y4);

	Bitmap^ surface1 = gcnew Bitmap(Width, Height);
	pictureBox4->Image = surface1;
	Color col1;
	for (int row = 0; row < Height; row++)
		for (int column = 0; column < Width; column++) {
			col1 = Color::FromArgb(draw_line[row*Width + column], draw_line[row*Width + column], draw_line[row*Width + column]);//RGB deðerler atanýr.
			surface1->SetPixel(column, row, col1);
		}
	this->pictureBox1->ImageLocation = draw_line_dialog->FileName;

	for (int pixel = 0; pixel < 256; pixel++) {
		this->hist->Series["Pixel Count"]->Points->AddXY(pixel, histogram[pixel]);
	}
}
private: System::Void conv_Click(System::Object^  sender, System::EventArgs^  e) {
	LPCTSTR input;
	CString str;

	k_means_histogram->Series->Clear();
	hist->Series->Clear();
	hist->Series->Add("Pixel Count");

	if (convolution_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		str   = convolution_dialog->FileName;
		input = (LPCTSTR)str;
		if (input != NULL)
			save_button->Enabled = true;
	}


	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);


	pictureBox1->Width = Width;
	pictureBox1->Height = Height;
	/*
		0.25,0.5,0.25,
		0.5,1,0.5,
		0.25,0.5,0.25
	*/

	pictureBox4->Width = Width;
	pictureBox4->Height = Height;

	double vertical_sobel[9] = {
				-1,0,1,
				-2,0,2,
				-1,0,1
	};

	double horizontal_sobel[9] = {
				1,2,1,
				0,0,0,
			  -1,-2,-1
	};

	double robinson[9] = {
			    -1,0,1,
				-1,0,1,
			    -1,0,1
	};

	double kirsch[9] = {
		-3,-3,5,
		-3,0,5,
		-3,-3,5
	};

	double kernel[49] = {

0.000036,	0.000363,	0.001446,	0.002291,	0.001446,	0.000363,	0.000036,
0.000363,	0.003676,	0.014662,	0.023226,	0.014662,	0.003676,	0.000363,
0.001446,	0.014662,	0.058488,	0.092651,	0.058488,	0.014662,	0.001446,
0.002291,	0.023226,	0.092651,	0.146768,	0.092651,	0.023226,	0.002291,
0.001446,	0.014662,	0.058488,	0.092651,	0.058488,	0.014662,	0.001446,
0.000363,	0.003676,	0.014662,	0.023226,	0.014662,	0.003676,	0.000363,
0.000036,	0.000363,	0.001446,	0.002291,	0.001446,	0.000363,	0.000036

	};

	int* histogram = Histogram(raw_intensity, Width, Height);
	BYTE* mask = Convolution(raw_intensity, Width, Height, vertical_sobel, 3);

	Bitmap^ surface1 = gcnew Bitmap(Width, Height);
	pictureBox4->Image = surface1;
	Color col1;
	for (int row = 0; row < Height; row++)
		for (int column = 0; column < Width; column++) {
			col1 = Color::FromArgb(mask[row*Width + column], mask[row*Width + column], mask[row*Width + column]);//RGB deðerler atanýr.
			surface1->SetPixel(column, row, col1);
		}
	this->pictureBox1->ImageLocation = convolution_dialog->FileName;

	for (int pixel = 0; pixel < 256; pixel++) {
		this->hist->Series["Pixel Count"]->Points->AddXY(pixel, histogram[pixel]);
	}
}

private: System::Void k_means_Click(System::Object^  sender, System::EventArgs^  e) {
	LPCTSTR input;
	CString str;

	hist->Series->Clear();
	hist->Series->Add("Pixel Count");
	k_means_histogram->Series->Clear();
	k_means_histogram->Series->Add("K-Means");

	if (k_means_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		str = k_means_dialog->FileName;
		input = (LPCTSTR)str;
		if (input != NULL)
			save_button->Enabled    = true;
	}

	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

	int* histogram = Histogram(raw_intensity, Width, Height);
	BYTE* k_means = K_Means(raw_intensity, histogram, Width, Height);
	int* k_means_hist = Histogram(k_means, Width, Height);

	
	pictureBox1->Width = Width;
	pictureBox1->Height = Height;

	pictureBox4->Width = Width;
	pictureBox4->Height = Height;

	int temp;

	Bitmap^ surface1 = gcnew Bitmap(Width, Height);
	pictureBox4->Image = surface1;
	Color col1;

	for (int row = 0; row < Height; row++)
		for (int column = 0; column < Width; column++) {
			temp = 0;
			col1 = Color::FromArgb(k_means[row*(Width)+ column], k_means[row*(Width) + column], k_means[row*(Width) + column]);//RGB deðerler atanýr.
			surface1->SetPixel(column, row, col1);
		}
	this->pictureBox1->ImageLocation = k_means_dialog->FileName;
	
	for (int pixel = 0; pixel < 256; pixel++) {
		this->hist->Series["Pixel Count"]->Points->AddXY(pixel, histogram[pixel]);
	}
	
	for (int pixel = 0; pixel < 256; pixel++) {
		this->k_means_histogram->Series["K-Means"]->Points->AddXY(pixel, k_means_hist[pixel]);
	}


}		 
		 
private: System::Void Not_Click(System::Object^  sender, System::EventArgs^  e) {
	LPCTSTR input;
	CString str;

	hist->Series->Clear();
	hist->Series->Add("Pixel Count");
	k_means_histogram->Series->Clear();

	if (notDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		str = notDialog->FileName;
		input = (LPCTSTR)str;
		if (input != NULL)
			save_button->Enabled = true;
	}

	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

	int* histogram = Histogram(raw_intensity, Width, Height);
	BYTE* not_image = Not(raw_intensity, Width, Height);

	Bitmap^ surface1 = gcnew Bitmap(Width, Height);
	pictureBox4->Image = surface1;
	Color col1;
	for (int row = 0; row < Height; row++)
		for (int column = 0; column < Width; column++) {
			col1 = Color::FromArgb(not_image[row*Width + column], not_image[row*Width + column], not_image[row*Width + column]);//RGB deðerler atanýr.
			surface1->SetPixel(column, row, col1);
		}
	this->pictureBox1->ImageLocation = notDialog->FileName;

	for (int pixel = 0; pixel < 256; pixel++) {
		this->hist->Series["Pixel Count"]->Points->AddXY(pixel, histogram[pixel]);
	}

}

private: System::Void reverse_button_Click(System::Object^  sender, System::EventArgs^  e) {
	LPCTSTR input;
	CString str;

	hist->Series->Clear();
	hist->Series->Add("Pixel Count");
	k_means_histogram->Series->Clear();

	if (reverseDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		str = reverseDialog->FileName;
		input = (LPCTSTR)str;
		if (input != NULL)
			save_button->Enabled = true;
	}

	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

	int* histogram = Histogram(raw_intensity, Width, Height);
	BYTE* reverse_image = Reverse(raw_intensity, Width, Height);

	Bitmap^ surface1 = gcnew Bitmap(Width, Height);
	pictureBox4->Image = surface1;
	Color col1;
	for (int row = 0; row < Height; row++)
		for (int column = 0; column < Width; column++) {
			col1 = Color::FromArgb(reverse_image[row*Width + column], reverse_image[row*Width + column], reverse_image[row*Width + column]);//RGB deðerler atanýr.
			surface1->SetPixel(column, row, col1);
		}
	this->pictureBox1->ImageLocation = reverseDialog->FileName;

	for (int pixel = 0; pixel < 256; pixel++) {
		this->hist->Series["Pixel Count"]->Points->AddXY(pixel, histogram[pixel]);
	}
}

private: System::Void bounding_box_click(System::Object^  sender, System::EventArgs^  e) {
	LPCTSTR input;
	CString str;

	hist->Series->Clear();
	hist->Series->Add("Pixel Count");
	k_means_histogram->Series->Clear();
	k_means_histogram->Series->Add("K-Means");

	if (k_means_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		str = k_means_dialog->FileName;
		input = (LPCTSTR)str;
		if (input != NULL)
			save_button->Enabled = true;
	}

	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

	int* histogram = Histogram(raw_intensity, Width, Height);
	BYTE* k_means = K_Means(raw_intensity, histogram, Width, Height);
	//BYTE* dilation = Dilation(k_means, Width, Height);
	//BYTE* erosion = Erosion(k_means, Width, Height);
	BYTE* labeled_image = Labeling(k_means, Width, Height);
	int* k_means_hist = Histogram(labeled_image, Width, Height);

	pictureBox1->Width = Width;
	pictureBox1->Height = Height;

	pictureBox4->Width = Width;
	pictureBox4->Height = Height;

	int temp;

	Bitmap^ surface1 = gcnew Bitmap(Width, Height);
	pictureBox4->Image = surface1;
	Color col1;

	for (int row = 0; row < Height; row++)
		for (int column = 0; column < Width; column++) {
			temp = 0;
			col1 = Color::FromArgb(labeled_image[row*(Width)+column], labeled_image[row*(Width)+column], labeled_image[row*(Width)+column]);//RGB deðerler atanýr.
			surface1->SetPixel(column, row, col1);
		}
	this->pictureBox1->ImageLocation = k_means_dialog->FileName;

	for (int pixel = 0; pixel < 256; pixel++) {
		this->hist->Series["Pixel Count"]->Points->AddXY(pixel, histogram[pixel]);
	}
	int a = 0;
	for (int pixel = 0; pixel < 256; pixel++) {
		this->k_means_histogram->Series["K-Means"]->Points->AddXY(pixel, k_means_hist[pixel]);
		if (k_means_hist[pixel] > 0)
			a++;
	}
	a -= 2; //255 durumu ve box degeri çýkarýlýr.
	MessageBox::Show("" + a);

}
private: System::Void zoom_click(System::Object^  sender, System::EventArgs^  e) {
	LPCTSTR input;
	CString str;

	hist->Series->Clear();
	hist->Series->Add("Pixel Count");
	k_means_histogram->Series->Clear();
	k_means_histogram->Series->Add("K-Means");

	if (k_means_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		str = k_means_dialog->FileName;
		input = (LPCTSTR)str;
		if (input != NULL)
			save_button->Enabled = true;
	}

	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);
	BYTE* cutted = Cut(raw_intensity, Width, Height, x1, y1, x4, y4);

	pictureBox1->Width = Width;
	pictureBox1->Height = Height;

	Width = x4 - x1;
	Height = y4 - y1;

	BYTE* zoom = Zoom(cutted, x4 - x1, y4 - y1);


	Width = 2 * Width - 1;
	Height = 2 * Height - 1;

	pictureBox4->Width = Width;
	pictureBox4->Height = Height;

	int temp;

	Bitmap^ surface1 = gcnew Bitmap(Width, Height);
	pictureBox4->Image = surface1;
	Color col1;

	for (int row = 0; row < Height; row++)
		for (int column = 0; column < Width; column++) {
			temp = 0;
			col1 = Color::FromArgb(zoom[row*(Width)+column], zoom[row*(Width)+column], zoom[row*(Width)+column]);//RGB deðerler atanýr.
			surface1->SetPixel(column, row, col1);
		}
	this->pictureBox1->ImageLocation = k_means_dialog->FileName;

	
}
private: System::Void dilation_click_Click(System::Object^  sender, System::EventArgs^  e) {
	LPCTSTR input;
	CString str;

	hist->Series->Clear();
	hist->Series->Add("Pixel Count");
	k_means_histogram->Series->Clear();
	k_means_histogram->Series->Add("K-Means");

	if (k_means_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		str = k_means_dialog->FileName;
		input = (LPCTSTR)str;
		if (input != NULL)
			save_button->Enabled = true;
	}

	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

	int* histogram = Histogram(raw_intensity, Width, Height);
	BYTE* k_means = K_Means(raw_intensity, histogram, Width, Height);
	BYTE* dilation = Dilation(k_means, Width, Height);
	int* k_means_hist = Histogram(dilation, Width, Height);

	pictureBox1->Width = Width;
	pictureBox1->Height = Height;

	pictureBox4->Width = Width;
	pictureBox4->Height = Height;

	int temp;

	Bitmap^ surface1 = gcnew Bitmap(Width, Height);
	pictureBox4->Image = surface1;
	Color col1;

	for (int row = 0; row < Height; row++)
		for (int column = 0; column < Width; column++) {
			temp = 0;
			col1 = Color::FromArgb(dilation[row*(Width)+column], dilation[row*(Width)+column], dilation[row*(Width)+column]);//RGB deðerler atanýr.
			surface1->SetPixel(column, row, col1);
		}
	this->pictureBox1->ImageLocation = k_means_dialog->FileName;

	for (int pixel = 0; pixel < 256; pixel++) {
		this->hist->Series["Pixel Count"]->Points->AddXY(pixel, histogram[pixel]);
	}
}
private: System::Void erosion_click_Click(System::Object^  sender, System::EventArgs^  e) {
	LPCTSTR input;
	CString str;

	hist->Series->Clear();
	hist->Series->Add("Pixel Count");
	k_means_histogram->Series->Clear();
	k_means_histogram->Series->Add("K-Means");

	if (k_means_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		str = k_means_dialog->FileName;
		input = (LPCTSTR)str;
		if (input != NULL)
			save_button->Enabled = true;
	}

	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

	int* histogram = Histogram(raw_intensity, Width, Height);
	BYTE* k_means = K_Means(raw_intensity, histogram, Width, Height);
	BYTE* erosion = Erosion(k_means, Width, Height);
	int* k_means_hist = Histogram(erosion, Width, Height);

	pictureBox1->Width = Width;
	pictureBox1->Height = Height;

	pictureBox4->Width = Width;
	pictureBox4->Height = Height;

	int temp;

	Bitmap^ surface1 = gcnew Bitmap(Width, Height);
	pictureBox4->Image = surface1;
	Color col1;

	for (int row = 0; row < Height; row++)
		for (int column = 0; column < Width; column++) {
			temp = 0;
			col1 = Color::FromArgb(erosion[row*(Width)+column], erosion[row*(Width)+column], erosion[row*(Width)+column]);//RGB deðerler atanýr.
			surface1->SetPixel(column, row, col1);
		}
	this->pictureBox1->ImageLocation = k_means_dialog->FileName;

	for (int pixel = 0; pixel < 256; pixel++) {
		this->hist->Series["Pixel Count"]->Points->AddXY(pixel, histogram[pixel]);
	}

}

};
}
