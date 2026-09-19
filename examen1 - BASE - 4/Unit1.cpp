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
// 1) Función que devuelva la posición de la última
// ocurrencia de un carácter z en una cadena x.
//
// Ej:
// x = "hola laLAs", z = 'a'  => 7

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
//2) Proceso para rotar una posición a derecha.
//
//V = [3, 7, 6, 5, 4, 3]   n = 5
//=> V = [3, 7, 6, 5, 4]



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

void CargarMatriz(TStringGrid *m, byte f, byte c, byte n, int &num) {
	if (f < n) // caso general
	{
		if (c < n)
		{
			if (f + c < n)
			{
				m->Cells[c][f] = ((f + c + 1) * (f + c + 2)) / 2 - f;
			}
			else
			{
				m->Cells[c][f] = "";
			}

			CargarMatriz(m, f, c + 1, n, num);
		}
		else
		{
			CargarMatriz(m, f + 1, 0, n, num);
		}
	}
}


void __fastcall TForm1::Button4Click(TObject *Sender) {
	//
	byte n = StrToInt(Edit1->Text);
	int num = 1;

	StringGrid1->ColCount = n;
	StringGrid1->RowCount = n;

	CargarMatriz(StringGrid1, 0, 0, n, num);
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	byte n = StrToInt(Edit1->Text);

	StringGrid1->ColCount = n;
	StringGrid1->RowCount = 1;
}
//---------------------------------------------------------------------------
