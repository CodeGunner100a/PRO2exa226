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
// Elimina de la cadena x la palabra o carácter indicado en z
void Eliminar(String &x, String z, byte p) {
    // Caso general: verificamos que la posición p esté dentro de la cadena
    if (p <= x.Length()) {
        // Verificamos si el carácter actual coincide con z
        // También se acepta la versión en mayúscula.
        // Además, comprobamos que sea el último carácter
        // o que después haya un espacio, para identificarlo como palabra.
        if ((x[p] == z[1] || x[p] == UpperCase(z)[1]) &&
            (p == x.Length() || x[p + 1] == ' ')) {
            // Si encontramos el carácter, lo eliminamos de la cadena.
            x.Delete(p, 1);
        }
        // Si no encontramos el carácter, avanzamos a la siguiente posición.
        else {
            Eliminar(x, z, p + 1);
        }
    }
}

void __fastcall TForm1::Button2Click(TObject *Sender) {
	// 1
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

// Carga en un vector los dígitos primos encontrados en la cadena x
void CargarDigVec(TStringGrid *v, String x, byte a, byte b) {
    // Calculamos cuántos espacios quedan disponibles en el vector.
    // a = posición inicial
    // b = posición final
    byte n = b - a + 1;
    // Caso general: mientras todavía haya espacio disponible.
    if (n > 0) {
        // Verificamos si el primer carácter de x es un dígito primo:
        // 2, 3, 5 o 7.
        if (x[1] == '2' || x[1] == '3' ||
            x[1] == '5' || x[1] == '7') {
            // Guardamos el dígito encontrado en la posición a del vector.
            v->Cells[a][0] = x[1];
            // Avanzamos a la siguiente posición del vector.
            a++;
        }
        // Eliminamos el primer carácter de x
        // para poder analizar el siguiente carácter.
        x.Delete(1, 1);
        // Llamada recursiva: repetimos el proceso con el resto de la cadena.
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
