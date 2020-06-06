//
// Created by joaquin_ramirez on 5/1/20.
//

#ifndef PRACTICE_FUNCIONES_H
#define PRACTICE_FUNCIONES_H

#include <iostream>
#include <cstddef>
using namespace std;

namespace utec {
    inline  namespace first{
        template <typename T>
        class Persona{
        protected:
            int edad;
            char sexo;
            string nombre;
            T dinero;
        public:
            Persona(){ edad = 18; sexo = 'M'; nombre = "Feojudo"; dinero = 0; cout << "Persona creada" << endl;}
            Persona(int _edad, char _sexo,string _nombre, T _dinero){
                edad = _edad; sexo = _sexo;nombre = _nombre; dinero = _dinero;}
             void hablar(){cout << "Soy laucito";};
            virtual ~Persona() = default;

            virtual void info() { cout << "Persona info"<<endl;}
        };

        template<typename T>
        class Alumno : public Persona<T>{
        private:
            T ponderado;
            int bikas;
        public:

            Alumno(): Persona<T>(){ponderado = 10.49; bikas = 69;}
            Alumno(int _edad, char _sexo, string _nombre, T _dinero,T _ponderado, int _bikas): Persona<T>(_edad,_sexo,_nombre,_dinero),ponderado(_ponderado),
            bikas(_bikas){}
            void info(){cout << "Mi ponderado es " << ponderado << endl << "Me llamo " << Persona<T>::nombre << endl;}
            void hablar() override {cout << "LAU!!!" << endl;}
            virtual ~Alumno() = default;
        };

    }
}
// Created by joaquin_ramirez on 5/1/20.

#endif //PRACTICE_FUNCIONES_H
