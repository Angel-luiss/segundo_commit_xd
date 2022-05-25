#pragma once
#include<iostream>
#include <mysql.h>
#include <string>
#include "ConexionBD.h"

using namespace std;
class Producto{
private: string idproducto,idmarca;

public: string nombre_producto, descripcion,imagen,fechaingreso;
		 int existencia=0;
		 float precio_costo=0.0, precio_venta=0.0;

public: 
	Producto() {
	}
	Producto(string idprod,string nprod,string idma, string des,string img, float pcosto, float pventa, int exis,string f_in) {
		idproducto = idprod;
		nombre_producto = nprod;
		idmarca = idma;
		descripcion = des;
		imagen = img;
		precio_costo = pcosto;
		precio_venta = pventa;
		existencia = exis;
		fechaingreso = f_in;
	}


	void crear() {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(precio_costo);
		string tt = to_string(precio_venta);
		string ttt = to_string(existencia);
		

		if (cn.getconectar()) {
			string insertar = "insert into productos(idproducto,nombre_producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso) values('" + idproducto + "','" + nombre_producto + "','" + idmarca + "','" + descripcion + "','" + imagen + "'," + t + "," + tt + "," + ttt + ",'" + fechaingreso + "');";
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
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_query = mysql_query(cn.getconectar(), c);
			cout << "\n---------- Productos ----------\n";
			cout << "\nidproducto,nombre_producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso\n\n";
			if (!q_query) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7] << " , " << fila[8] << endl;

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
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		int aux;
		cout << "ingrese id a actualizar " << endl;
		cin >> aux;
		string aux_j = to_string(precio_costo);
		string auxi = to_string(precio_venta);
		string auxii = to_string(existencia);
		string i = to_string(aux);

		if (cn.getconectar()) {
			string update = "update productos SET idproducto = '" + idproducto + "', nombre_producto = '" + nombre_producto + "', idmarca = '" + idmarca + "', descripcion = '" + descripcion + "',imagen = '" + imagen + "', precio_costo =" + aux_j + ", precio_venta = " + auxi + ", existencia = " + auxii + ",fechaingreso = '" + fechaingreso + "',where idproducto = " + i + ";";
			const char* upda = update.c_str();
			q_estado = mysql_query(cn.getconectar(), upda);
			if (!q_estado) {
				cout << " modificado " << endl;
			}
			else {
				cout << "error xxx" << endl;
			}

		}
		else {
			cout << " error de conexion xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar(int x) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string where = to_string(x);
		if (cn.getconectar()) {
			string eliminar = "delete from productos where idproducto = " + where + ";";
			const char* eli = eliminar.c_str();
			q_estado = mysql_query(cn.getconectar(), eli);
			if (!q_estado) {
				cout << " BORRADO EXITOSO !!!!!" << endl;
			}
			else {
				cout << " xxx ERROR al hacer DELETE xxx " << endl;
			}
		}
		else {
			cout << "xxx ERROR DE CONEXION xxx" << endl;
		}
		cn.cerrar_conexion();
	}

};



