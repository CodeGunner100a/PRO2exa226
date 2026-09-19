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

// EXAMENE
// ---------------------------------------------------------------------------

// EJERCICIO 1

void Eliminar(String &x, String z, byte p) {
	if (p <= x.Length()) // caso general
	{
		if (x.SubString(p, z.Length()) == z && (p == 1 || x[p - 1] == ' ') &&
			(p + z.Length() > x.Length() || x[p + z.Length()] == ' ')) {

			if (p == 1) {
				x.Delete(p, z.Length() + 1);
			}
			else {
				x.Delete(p - 1, z.Length() + 1);
			}
		}
		else {
			Eliminar(x, z, p + 1);
		}
	}
}

void __fastcall TForm1::Button2Click(TObject *Sender) {
	// 1  LLAMADA DEL EJERCICIO 1
	String x = Edit1->Text;
	String z = Edit2->Text;

	Eliminar(x, z, 1);

	Edit3->Text = x;

}

// ---------------------------------------------------------------------------

// EJERCICIO 2
byte ContPrim(String x) {
	byte c;

	if (x == "") // caso base
	{
		c = 0;
	}
	else // caso general
	{
		wchar_t z = x[1];
		x.Delete(1, 1);

		c = ContPrim(x);

		if (z == '2' || z == '3' || z == '5' || z == '7') {
			c++;
		}
	}

	return c;
}

void CargarDigVec(TStringGrid *v, String x, byte a, byte b) {
	byte n = b - a + 1;

	if (n > 0) {
		if (x[1] == '2' || x[1] == '3' || x[1] == '5' || x[1] == '7') {
			v->Cells[a][0] = x[1];
			a++;
		}

		x.Delete(1, 1);
		CargarDigVec(v, x, a, b);
	}
}

void __fastcall TForm1::Button3Click(TObject *Sender) {
	// 2

	String x = Edit1->Text;

	byte n = ContPrim(x);

	CargarDigVec(StringGrid1, x, 0, n - 1);

	StringGrid1->ColCount = n;
	StringGrid1->RowCount = 1;

	Edit3->Text = n;

}

// ---------------------------------------------------------------------------

// EJERCICIO 3

