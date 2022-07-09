/*2. ƒобавьте в проект новый файл IdCard.h и объ€вите новый класс IdCard,
который содержит два закрытых пол€ Ц номер карточки и статус
(категорию), а также соответствующие методы доступа к этим пол€м и
конструкторы :*/

#pragma once
#include <string>
using namespace std;
class IdCard
{
private:
	int number;
	   string category;
public:
	IdCard();
	IdCard(int);
	IdCard(int, string);
	void setNumber(int newNumber);
	int getNumber();
	void setCategory(string cat);
	string getCategory();
};