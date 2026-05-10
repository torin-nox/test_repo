//program demonstruje zasięg ideb=ntyfikatorów
#include <stdio.h>

void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);

int x = 2; //zmienna , która jest globalna

int main(void) {
    int x = 5; //zmienna lokalna wew funkcji main
    printf("Warttość x w lokalnym zasięgu funkcji main() wynosi: %d\n", x);
    {
        int x = 7;//nowy lokalny zasięg wew funkcji main()
        printf("Wartość zmiennej x wew nowego zsięgu {} wew funkcji main() wynosi: %d\n", x);
    }

    printf("Wychodzimy z lokalnego zasięgu {} i wracamy do zasięgu main() x: %d\n", x);
    useLocal();
    useLocal();
    useStaticLocal();
    useStaticLocal();
    useStaticLocal();
    useGlobal();
    useGlobal();
    useLocal();
    useStaticLocal();

    return 0;
}
//---------------------------------------------------------------------------------------------
void useLocal(void){
    int x = 25; //inicjalizowana w czasie każdego wywołania funkcji
    printf("Po rozpoczęciu wykonaia funkcji useLocal() wartość x wynosi: %d\n", x);
    ++x;
    printf("Po zakończeniu działania funkcji useLocal() wartość x wynosi: %d\n", x);
}

//----------------------------------------------------------------------------------------------
// useStaticLocal inicjalizuje zmienną statyczną tylko raz w trakcie pierwszego wykonani
// wartość x zostanie zachowana pomiędy wywołaniami tej funkcji
void useStaticLocal(void){
    static int x = 50;
    printf("Po rozpoczęciu wykonania funkcji useStaticLocal() wartość x wynosi: %d\n", x);
    ++x;
    printf("Po zakończeniu wykonania useStaticLocal() wartość x wynosi: %d\n", x);
}

//---------------------------------------------------------------------------------------------
// w trakcie każdego wykonania funkcja modyfikuje zmienną globalną x
void useGlobal(void) {
    printf("Po rozpoczeciu wykonania useGlobal() zmienna globalna x wynosi: %d\n", x);
    x *= 10;

    printf("Po zakończeniu działania useGlobal() zmienna globalna x wynosi: %d\n", x);
}
