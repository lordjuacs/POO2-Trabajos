//
// Created by utec on 4/4/20.
//

#ifndef POO2_UTEC_VECTOR_2020_1_VECTOR_UTEC_H
#define POO2_UTEC_VECTOR_2020_1_VECTOR_UTEC_H

#include <cstddef>

namespace utec {
    inline namespace beta {
        class vector_utec {
        private:
            int* data_ = nullptr;
            size_t size_ = 0;
            size_t capacity_ = 1;
        public:
            // Constructores
            vector_utec(size_t n);                              // Constructor por parametros
            vector_utec() = default;                            // Constructor por defecto
            vector_utec(const vector_utec& other);               // Constructor copia
            vector_utec&operator=(const vector_utec& other);        // Operador asignacion copia
            vector_utec(vector_utec&& other) noexcept;              // Constructor move
            vector_utec&operator=(vector_utec&& other) noexcept;    // Operador asignacion move


            ~vector_utec();

            void push_back(int item);
            void pop_back();
            void insert(size_t index, int item);
            void erase(size_t index);

            int& operator[](size_t index);                      // Escritura valores
            const int& operator[] (size_t index) const;         // Leer valores

            size_t size() const;
        };
    }
}


#endif //POO2_UTEC_VECTOR_2020_1_VECTOR_UTEC_H
