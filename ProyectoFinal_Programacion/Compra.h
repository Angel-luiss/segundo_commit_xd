/*#pragma once
#include <string>
#include <mysql.h>
#include "ConexionBD.h"
using namespace std;


class Compra
{
private: int idcompras = 0;
public: string no_orden_compra, idproveedor, fecha_orden, fecha_ingreso;
	  int idproveedores = 0;

public:
	Compra() {
	}
	Compra(int idcomp, int n_ord_com, int idp, string f_or, string f_in) {
		idcompras = idcomp;
		no_orden_compra = n_ord_com;
		idproveedor = idp;
		fecha_orden = f_or;
		fecha_ingreso = f_in;
	}



	void ingresar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		/*string aux_i = to_string(no_orden_compra);
		string aux_ii = to_string(idproveedor);* /*

		if (cn.getconectar()) {
			string insert = * *;
				/* "INSERT INTO compras(no_orden_compra,idproveedor,fecha_orden, fecha_ingreso)VALUES(" + aux_i + "," + aux_ii + ",'" + fecha_orden + "', '" + fecha_ingreso + "');";*/
/*			const char* i = insert.c_str();
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


}; */
