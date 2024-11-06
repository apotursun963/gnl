
/*
Global && Local Değişeknler;
1.Global Değişkenler:
Tanım -> Global değişkenler, bir programın başlangıcından itibaren programın herhangi bir noktasında erişilebilen 
ve kullanılabilen değişkenlerdir.Genellikle dosya başında veya herhangi bir fonksiyonun dışında tanımlanırlar.
Kapsam -> Global değişkenler, dosya kapsamına (file scope) sahiptir. Yani tanımlandıkları dosyanın herhangi bir yerinde erişilebilirler.
Ömür -> Global değişkenler, programın başlangıcından programın sonuna kadar bellekte kalır. Bu nedenle, programın yaşam süresi boyunca değişkenin değeri korunur.
Erişim -> Herhangi bir fonksiyon veya blok içinde, global değişkenlere erişmek için doğrudan değişken adını kullanabiliriz.

2.Yerel Değişkenler:
Tanım -> Yerel değişkenler, bir fonksiyonun veya bloğun içinde tanımlanan ve sadece tanımlandıkları kapsam(alan) içinde erişilebilen değişkenlerdir.
Kapsam -> Yerel değişkenler, blok kapsamına (block scope) sahiptir. Yani tanımlandıkları bloğun içinde geçerlidirler ve blok dışından erişilemezler.
Ömür -> Yerel değişkenler, tanımlandıkları bloğun çalışma süresi boyunca bellekte kalır ve blok dışında geçerli değildir.
Erişim -> Yerel değişkenlere, tanımlandıkları bloğun içinde erişilir. Başka bir fonksiyon veya blok dışından doğrudan erişilemezler.
*/


/*
Static Değişken:
Fonksiyon içinde tanımlanan static değişkenler, o fonksiyonun çağrıldığı her seferinde değerlerini korur.
Yani static olarak tanımlanan bir değişken, fonksiyonun çalışması bitse bile değerini saklar ve bir sonraki çağrıda bu değeri güncelleyebilir. 
Normalde bir fonksiyon içinde tanımlanan değişkenler fonksiyonun çalışması tamamlandıktan sonra bellekten silinirler(yani ömürleri fonksiyonun ömrü kadardır).
Ancak static olarak tanımlanan değişkenlerin ömrü farklıdır.Fonksiyon içinde tanımlanan static değişkenler, programın başlangıcından 
itibaren bellekte var olan ve fonksiyonun çalışması bittikten sonra bile bellekte kalmaya devam eden değişkenlerdir.(yani ömürleri programın ömrü kadardır)
*/

// normal değişken ve static değişken örneği yapalım
int get_counter()
{
    static int counter = 0;                // int counter = 0;
    counter++;
    return (counter);
}

#include <stdio.h>
int main()
{
    printf("%d\n", get_counter());
    printf("%d\n", get_counter());
    printf("%d\n", get_counter());
}
