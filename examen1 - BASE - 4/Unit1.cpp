// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

// EXAMENES
// ---------------------------------------------------------------------------

// EJERCICIO 1

byte UltimaOcurrencia(String x, String z, byte p) {
	byte pos;

	if (p > x.Length()) // caso base
	{
		pos = 0;
	}
	else // caso general
	{
		pos = UltimaOcurrencia(x, z, p + 1);

		if (x[p] == z[1] && pos == 0) {
			pos = p;
		}
	}

	return pos;
}

void __fastcall TForm1::Button2Click(TObject *Sender) {
	// 1

	String x = Edit1->Text;
	String z = Edit2->Text;

	byte pos = UltimaOcurrencia(x, z, 1);

	Edit3->Text = pos;

}

// ---------------------------------------------------------------------------

// EJERCICIO 2
void RotarDer(TStringGrid *v, byte p) {
	if (p > 1) // caso general
	{
		v->Cells[p][0] = v->Cells[p - 1][0];

		RotarDer(v, p - 1);
	}
}

void RotarDer(TStringGrid *v, byte p, String ult) {
	if (p > 1) // caso general
	{
		v->Cells[p - 1][0] = v->Cells[p - 2][0];

		RotarDer(v, p - 1, ult);
	}
	else // caso base
	{
		v->Cells[0][0] = ult;
	}
}

void __fastcall TForm1::Button3Click(TObject *Sender) {
	// 2
	byte n = StringGrid1->ColCount;

	String ult = StringGrid1->Cells[n - 1][0];

	RotarDer(StringGrid1, n, ult);
}

// ---------------------------------------------------------------------------

// EJERCICIO 3

void __fastcall TForm1::Button4Click(TObject *Sender) {
	// 3   LLAMADA DEL EJERCICIO 3 COPIAR ABAJO

}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    byte n = StrToInt(Edit1->Text);

	StringGrid1->ColCount = n;
	StringGrid1->RowCount = 1;
}
//---------------------------------------------------------------------------

