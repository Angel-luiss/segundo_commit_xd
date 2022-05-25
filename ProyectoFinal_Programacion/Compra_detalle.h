/*#pragma once
#include <string>
#include <mysql.h>
#include "ConexionBD.h"

using namespace std;

class Compra_detalle
{
private:
public: string idcompra, idproducto, cantidad, precio_costo_unitario;
	  int idcompra = 0;

public:
	Compra_detalle
	() {
	}
	Compra_detalle(int idcomp, int idprod, int cant, float pre_cos_uni) {
		idcompra = idcomp;
		idproducto = idprod;
		cantidad = cant;
		precio_costo_unitario = precio_costo_unitario;
	}

	void ingresar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string aux_i = to_string(idcompra);
		string aux_ii = to_string(idproducto);
		string aux_iii = to_string(cantidad);
		string aux_iiii = to_string(precio_costo_unitario);
		

		if (cn.getconectar()) {
			string insert =
				"INSERT INTO compras_detalles(idcompra, idproducto, cantidad, precio_costo_unitario)VALUES(" + aux_i + "," + aux_ii + "," + aux_iii + "," + aux_iiii + ");";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "ingreseo exitoso !!!!!!!!" << endl;
			}
			else {
				cout << "xxx ERROR AL HACER INSERT xxx" << endl;
			}
		}
		else {
			cout << " xxx ERROR en LA CONEXION xxx" << endl;
		}
		cn.cerrar_conexion();
	}

};

*/