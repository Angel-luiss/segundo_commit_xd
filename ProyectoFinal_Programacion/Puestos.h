#pragma once
#include <mysql.h>
#include <string>
#include "ConexionBD.h"
using namespace std;

class Puestos {
private: int idpuesto = 0;
public: string puesto;

public:
	Puestos() {
	}
	Puestos(int idpue, string pue) {
		idpuesto = idpue;
		puesto = pue;
	}

	void crear() {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string insertar = "insert into puestos(puesto) values('" + puesto + "');";
			const char* i = insertar.c_str();
			q_query = mysql_query(cn.getconectar(), i);
			if (!q_query) {
				cout << "Ingreso exitoso\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_query;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select * from puestos";
			const char* c = consulta.c_str();
			q_query = mysql_query(cn.getconectar(), c);
			cout << "\n---------- PUESTOS ----------\n";
			cout << "\nId Puesto, peusto\n\n";
			if (!q_query) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << endl;

				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string t = to_string(idpuesto);
			string update = "update marcas set puesto='" + puesto + "' where idpuesto=" + t + ";";
			const char* i = update.c_str();
			q_query = mysql_query(cn.getconectar(), i);
			if (!q_query) {
				cout << "Actualizacion exitosa\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();

	}

	void eliminar() {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string t = to_string(idpuesto);
			string elimin = "delete from productos where idpuesto=" + t + ";";
			const char* i = elimin.c_str();
			q_query = mysql_query(cn.getconectar(), i);
			if (!q_query) {
				cout << "Eliminacion exitosa\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();
	}
};

