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
void Eliminar(String &x, String z, byte p, byte &pos) {
	if (p <= x.Length()) // caso general
	{
		if (x[p] == z[1]) {
			pos = p;
		}

		Eliminar(x, z, p + 1, pos);
	}
	else // caso base
	{
		if (pos > 0) {
			x.Delete(pos, 1);
		}
	}
}

void __fastcall TForm1::Button2Click(TObject *Sender) {
	// 1
	String x = Edit1->Text;
	String z = Edit2->Text;

	byte pos = 0;

	Eliminar(x, z, 1, pos);

	Edit3->Text = x;
}

// ---------------------------------------------------------------------------

// EJERCICIO 2
byte ContVocal(String x) {
	byte c;

	if (x == "") // caso base
	{
		c = 0;
	}
	else // caso general
	{
		wchar_t z = x[1];
		x.Delete(1, 1);

		c = ContVocal(x);

		if (z == 'a' || z == 'e' || z == 'i' || z == 'o' || z == 'u') {
			c++;
		}
	}

	return c;
}

void CargarVocal(TStringGrid *v, String x, byte a, byte b) {
	byte n = b - a + 1;

	if (n > 0) {
		if (x[1] == 'a' || x[1] == 'e' || x[1] == 'i' || x[1] == 'o' ||
			x[1] == 'u') {

			v->Cells[a][0] = x[1];
			a++;
		}

		x.Delete(1, 1);
		CargarVocal(v, x, a, b);
	}
}

void __fastcall TForm1::Button3Click(TObject *Sender) {
	// 2
String x = Edit1->Text;

	byte n = ContVocal(x);

	CargarVocal(StringGrid1, x, 0, n - 1);

	StringGrid1->ColCount = n;
	StringGrid1->RowCount = 1;

	Edit3->Text = n;


}

// ---------------------------------------------------------------------------

// EJERCICIO 3

void CargarDonut(TStringGrid *m, byte f, byte c, byte nf, byte nc, byte d) {
	if (f < nf) // caso general
	{
		if (c < nc) {
			if (f == 0 || f == nf - 1 || c == 0 || c == nc - 1) {

				m->Cells[c][f] = d;
			}
			else {
				m->Cells[c][f] = 0;
			}

			CargarDonut(m, f, c + 1, nf, nc, d);
		}
		else {
			CargarDonut(m, f + 1, 0, nf, nc, d);
		}
	}
}

void __fastcall TForm1::Button4Click(TObject *Sender) {
	// 3

	byte m = StrToInt(Edit1->Text);
	byte n = StrToInt(Edit2->Text);
	byte d = StrToInt(Edit3->Text);

	StringGrid1->RowCount = m;
	StringGrid1->ColCount = n;

	CargarDonut(StringGrid1, 0, 0, m, n, d);

}
// ---------------------------------------------------------------------------
