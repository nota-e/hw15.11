#include <iostream>
#include <string>

template<typename T>
T minOf(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template<typename T, size_t N>
T arraySum(const T (&data)[N]) {
    T sum{};
    for (size_t i = 0; i < N; ++i) {
        sum += data[i];
    }
    return sum;
}

template<typename T, typename K>
void printPair(const T& first, const K& second) {
    std::cout << first << " - " << second << std::endl;
}

template<typename T, typename K, typename V>
void makeTriple(const T& first, const K& second, const V& third) {
    std::cout << "[" << first << ", " << second << ", " << third << "]" << std::endl;
}

template<typename T, typename U = const T*>
const T* maxPtr(const T* a, U b) {
    const T* ptrB = b;
    if (a == nullptr) return ptrB;
    if (ptrB == nullptr) return a;
    return (*a > *ptrB) ? a : ptrB;
}

int main() {
    // Задача 1
    std::cout << "=== Задача 1: minOf ===" << std::endl;
    std::cout << "min(4, 5) = " << minOf(4, 5) << std::endl;
    std::cout << "min(3.4, 2.3) = " << minOf(3.4, 2.3) << std::endl;
    std::cout << "min(\"apple\", \"banana\") = "
              << minOf(std::string("apple"), std::string("banana")) << std::endl;

    // Задача 2
    std::cout << "\n=== Задача 2: arraySum ===" << std::endl;
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.5, 2.5, 3.0};
    std::cout << "int sum: " << arraySum(intArr) << std::endl;
    std::cout << "double sum: " << arraySum(doubleArr) << std::endl;

    // Задача 3
    std::cout << "\n=== Задача 3: printPair ===" << std::endl;
    printPair(42, std::string("ответ"));
    printPair(3.14, 100);

    // Задача 4
    std::cout << "\n=== Задача 4: makeTriple ===" << std::endl;
    makeTriple(1, 2.5, std::string("три"));
    makeTriple(std::string("x"), 42, 3.14);

    // Задача 5
    std::cout << "\n=== Задача 5: maxPtr ===" << std::endl;
    int a = 3, b = 7;
    std::cout << "*maxPtr(&a, &b) = " << *maxPtr(&a, &b) << std::endl;
    std::cout << "*maxPtr(&a, nullptr) = " << *maxPtr(&a, nullptr) << std::endl;
    std::cout << "maxPtr(nullptr, nullptr) = "
              << (maxPtr<int>(nullptr, nullptr) == nullptr ? "nullptr" : "не nullptr") << std::endl;

    return 0;
}
