#include <iostream>

// Этот метод копирования более эффективный, чем копирование элементов в цикле, так как позволяет скопировать несколько элементов за одну операцию. 

//используем шаблон, чтобы копировать массивы вне зависимости от типов элеметов в них
template <typename InputIt, typename OutputIt>
void array_copy(InputIt begin, InputIt end, OutputIt d_begin) 
{
    int size = 8 / sizeof(*begin);
    int div = (end - begin) / size; 
    int mod = (end - begin) % size; 

    // копируем блоки памяти
    for (int i = 0; i < div; i += 1)
    {
        auto src = (long long*)(begin);
        auto point = (long long*)(d_begin);
        *point = *src;
        begin += size;
        d_begin += size;
    }

    // копируем оставшиеся элементы
    for (int i = 0; i < mod; ++i)
    {
        *(d_begin + i) = *(begin + i);
    }
}


int main() {
    const int n = 25;
    int mas1[n];
    int mas2[n];
    {
        mas1[i] = i * 2;
    }

    array_copy(&mas1[0], &(mas1[0]) + n, &mas2[0]);
    for (int i = 0; i < n; ++i) 
    {
        std::cout << mas1[i] << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < n; ++i) 
    {
        std::cout << mas2[i] << " ";
    }
    return 0;
}