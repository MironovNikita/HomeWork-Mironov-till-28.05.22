#pragma once
class String
{
private:
	char* ar = new char[0];
	
	//Проверка индекса
	int checkIndex(int index, int size)
	{
		if (index > size) return size;
		else return index;
	}
	//Проверка количества после индекса
	int checkQuant(int index, int quant, int size)
	{
		if (index + quant > size) return size - index;
		else return quant;
	}

public:
	String()
	{ 

	}
	String(char* str)
	{
		this->ar = str;
	}

	//Перегрузка оператора для создания копии строки
	void operator = (String& str)
	{
		this->ar = str.ar;
	}

	//Деструктор (It's working! ^-^)
	~String()
	{
		cout << endl << "Delete: " << this << endl;
		delete[]ar;
	}

	//Вывод строки
	void out()
	{
		int counter = 0;
		cout << endl << "\"";
		
		for (int i = 0; ar[i] != '\0'; i++)
		{
			cout << ar[i];
			counter++;
		}
		cout << "\"" << endl;
		cout << "Adress: " << this << endl;
		if (counter == 0) cout << "Empty!";
	}

	//1 Возвращает длину строки
	int size()
	{
		int size = 0;
		for (int i = 0; ar[i] != '\0'; i++)
		{
			size++;
		}
		return size;
	}

	//2 Изменяет длину строки
	void reSize(int n)
	{
		int length = size();
		n = checkIndex(n, length);
		
		char* buf = new char[n + 1];

		for (int i = 0; i < n; i++)
		{
			buf[i] = ar[i];
		}
		buf[n] = '\0';
		delete[]ar;
		ar = buf;
	}

	void reSize(int n, char s)
	{
		int length = size();
		char* buf = new char[n + 1];
		for (int i = 0; i < length && ar[i]!='\0'; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = length; i < n; i++)
		{
			buf[i] = s;
		}
		buf[n] = '\0';
		delete[]ar;
		ar = buf;
	}

	//3 Очищает строку, она становится пустой
	void clear()
	{
		char* buf = new char[1]{ "" };
		buf[0] = '\0';
		delete[]ar;
		ar = buf;
	}

	//4 Возвращает true, если строка пуста, false - если нет
	bool empty()
	{
		int length = size();
		if (length == 0) return true;
		else return false;
	}

	//5 Добавляет в конец строки символ (вызывается с одним параметром типа char)
	void push_back(char s)
	{
		int length = size();
		char* buf = new char[length + 2];
		for (int i = 0; i < length; i++)
		{
			buf[i] = ar[i];
		}
		
		buf[length] = s;
		buf[length + 1] = '\0';
		delete[]ar;
		ar = buf;
	}

	//6 Добавляет в конец строки несколько символов, другую строку или фрагмент другой строки. Имеет несколько способов вызова
	//Добавление нескольких символов
	void append(int q, char s)
	{
		int length = size();
		char* buf = new char[length + q + 1];
		for (int i = 0; i < length; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = length; i < length + q; i++)
		{
			buf[i] = s;
		}
		buf[length + q] = '\0';
		delete[]ar;
		ar = buf;
	}

	//Добавляет в конец строки содержимое другой строки
	void append(String &str2)
	{
		int length1 = size();
		int length2 = str2.size();

		char* buf = new char[length1 + length2 + 1];
		for (int i = 0; i < length1; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = length1, k = 0; i < length1 + length2; i++)
		{
			buf[i] = str2.ar[k++];
		}
		buf[length1 + length2] = '\0';
		delete[]ar;
		ar = buf;
	}

	/*Добавляет в конец строки содержимое другой строки, начиная с символа, имеющего заданный индекс, с заданным количеством сим-
	волов. Если оставшихся от текущего индекса символов меньше, чем введено, выведутся все оставшиеся во второй строке символы.*/
	void append(String& str2, int index, int quant)
	{
		int length1 = size();
		int length2 = str2.size();
		index = str2.checkIndex(index, length2);
		quant = str2.checkQuant(index, quant, length2);

		char* buf = new char[length1 + quant + 1];
		for (int i = 0; i < length1; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = length1, k = index; i < length1 + quant; i++)
		{
			buf[i] = str2.ar[k++];
		}
		buf[length1 + quant]='\0';
		delete[]ar;
		ar = buf;
	}

	//7 Удаление из строки её части. Имеет несколько вариантов:
	//Удаляет из исходной строки количество символов с индекса и до конца
	void erase(int index)
	{
		int length = size();
		index = checkIndex(index, length);

		char* buf = new char[index + 1];
		for (int i = 0; i < index; i++)
		{
			buf[i] = ar[i];
		}
		delete[]ar;
		ar = buf;
		ar[index] = '\0';
		length = index;
	}

	//Удаляет из строки с символа с индексом определённое количество элементов
	void erase(int index, int quant)
	{

		int length = size();
		index = checkIndex(index, length);
		quant = checkQuant(index, quant, length);
		char* buf = new char[length - quant + 1];

		for (int i = 0; i < index; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = index + quant, k = index; i < length; i++)
		{
			buf[k++] = ar[i];
		}
		buf[length - quant] = '\0';
		delete[]ar;
		ar = buf;
		
	}

	//8 Вставляет в середину строки несколько символов, другую строку или фрагмент другой строки.
	//Вставить несколько одинаковых символов, по введённому количеству.
	void insert(int index, int quant, char symbol)
	{
		int length = size();
		index = checkIndex(index, length);
		char* buf = new char[length + quant + 1];
		for (int i = 0; i < index; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = 0, k = index; i < quant; i++)
		{
			buf[k++] = symbol;
		}
		for (int i = index + quant, k = index; i < length + quant; i++)
		{
			buf[i] = ar[k++];
		}
		buf[length + quant] = '\0';
		delete[]ar;
		ar = buf;
	}

	//Вставить содержимое второй строки в первую с индекса
	void insert(String& str2, int index)
	{
		int length1 = size();
		int length2 = str2.size();
		index = checkIndex(index, length1);

		char* buf = new char[length1 + length2 + 1];
		for (int i = 0; i < index; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = index, k = 0; i < index + length2; i++)
		{
			buf[i] = str2.ar[k++];
		}
		for (int i = index + length2, l = index; i < length1 + length2; i++)
		{
			buf[i] = ar[l++];
		}
		buf[length1 + length2] = '\0';
		delete[]ar;
		ar = buf;
	}

	//Вставить содержимое второй строки в первую с индекса первой, используя индекс и количество символов второй
	void insert(String& str2, int index, int index2, int quant)
	{
		int length1 = size();
		int length2 = str2.size();
		index = checkIndex(index, length1);
		index2 = checkIndex(index2, length2);
		quant = checkQuant(index2, quant, length2);

		char* buf = new char[length1 + quant + 1];

		for (int i = 0; i < index; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = index2, k = index; i < index2 + quant; i++)
		{
			buf[k++] = str2.ar[i];
		}
		for (int i = index, l = index + quant; i<length1; i++)
		{
			buf[l++] = ar[i];
		}
		buf[length1 + quant] = '\0';
		delete[]ar;
		ar = buf;
	}

	//9 Возвращает подстроку как фрагмент исходной строки
	//Возвращает подстроку исходной строки начиная с индекса и до конца
	String substr(String& str1, int index)
	{
		int length = str1.size();
		index = checkIndex(index, length);
		char* buf = new char[length - index + 1];
		for (int i = index, k = 0; i < length; i++)
		{
			buf[k++] = str1.ar[i];
		}
		buf[length - index] = '\0';
		ar = buf;
		return ar;
	}

	//Возвращает подстроку исходной строки начиная индекса и определённое количество символов
	String substr(String& str1, int index, int quant)
	{
		int length = str1.size();
		index = checkIndex(index, length);
		quant = checkQuant(index, quant, length);
		char* buf = new char[quant + 1];

		for (int i = 0, k = index; i < quant; i++)
		{
			buf[i] = str1.ar[k++];
		}
		buf[quant] = '\0';
		ar = buf;
		return ar;

	}

	//10 Заменяет фрагмент строки на несколько равных символов, другую строку или фрагмент другой строки
	//Вставить определённое количество одинаковых символов вместо определённого диапазона символов с индекса исходной строки 
	void replace(int index, int quant1, int quant2, int symbol)
	{
		int length = size();
		index = checkIndex(index, length);
		quant1 = checkQuant(index, quant1, length);

		char* buf = new char[length - quant1 + quant2 + 1];
		for (int i = 0; i < index; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = 0, k = index; i < quant2; i++)
		{
			buf[k++] = symbol;
		}
		for (int i = index + quant1, k = index + quant2; i < length; i++)
		{
			buf[k++] = ar[i];
		}
		buf[length - quant1 + quant2] = '\0';
		delete[]ar;
		ar = buf;
	}

	//Вставить содержимое второй строки вместо диапазона символов, которые будут заменеы с индекса исходной строки 
	void replace(int index, int quant, String& str2)
	{
		int length1 = size();
		int length2 = str2.size();
		index = checkIndex(index, length1);
		quant = checkQuant(index, quant, length1);

		char* buf = new char[length1 - quant + length2 + 1];

		for (int i = 0; i < index; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = 0, k = index; i < length2; i++)
		{
			buf[k++] = str2.ar[i];
		}
		for (int i = index + quant, k = index + length2; i < length1; i++)
		{
			buf[k++] = ar[i];
		}
		buf[length1 - quant + length2] = '\0';
		delete[]ar;
		ar = buf;
	}

	//Вставить несколько символов второй строки с определённого индекса вместо диапазона символов, которые будут заменеы с индекса исходной строки 
	void replace(int index, int quant1, String& str2, int index2, int quant3)
	{
		int length1 = size();
		int length2 = str2.size();
		index = checkIndex(index, length1);
		quant1 = checkQuant(index, quant1, length1);
		index2 = checkIndex(index2, length2);
		quant3 = checkQuant(index2, quant3, length2);

		char* buf = new char[length1 - quant1 + quant3 + 1];

		for (int i = 0; i < index; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = 0, k = index, l = index2; i < quant3; i++)
		{
			buf[k++] = str2.ar[l++];
		}
		for (int i = index + quant1, k = index2 + quant3; i < length1; i++)
		{
			buf[k++] = ar[i];
		}
		buf[length1 - quant1 + quant3] = '\0';
		delete[]ar;
		ar = buf;
	}

	//11 Ищет в данной строке первое вхождение другой строки. Возвращается индекс первого символа, начиная с которого далее идёт подстрока, равная исходной строке
	//Искать первое вхожджение строки начиная с индекса. Если он не задан, то поиск осуществляется с начала
	int find(String& str4, int index = 0)
	{
		int length1 = size();
		int length2 = str4.size();
		bool flag;

		index = checkIndex(index, length1);

		for (int i = 0; i < length1; i++)
		{
			if (ar[i] == str4.ar[0])
			{
				flag = true;
				for (int j = 1; j < length2; j++)
				{
					if (ar[i + j] != str4.ar[j])
					{
						flag = false;
						break;
					}
				}
				if (flag == true) return i;
			}
		}
		return -1;
	}

	//Искать в исходной строке подстроку, равную первым нескольким символам исходной строки
	int find(String& str4, int index, int quant)
	{
		int length1 = size();
		int length2 = str4.size();
		bool flag;

		index = checkIndex(index, length1);

		if (quant > length2) quant = length2;
		if (quant < 0) quant = 0;

		for (int i = index; i < length1; i++)
		{
			if (ar[i] == str4.ar[0])
			{
				//Здесь проверить на то, как количественно задать, что равно кол-ву искомых элементов
				flag = true;
				for (int j = 1; j < length2; j++)
				{
					if (ar[i + j] != str4.ar[j])
					{
						flag = false;
						break;
					}
				}
				if (flag == true) return i;
			}
		}
		return -1;
	}

	//12 Ищет последнее вхождение подстроки ("правый поиск")
	//Искать первое вхожджение строки начиная с индекса (с конца)
	int rfind(String& str5, int index = 0)
	{
		int length1 = size();
		int length2 = str5.size();
		bool flag;
		index = length1 - index; //Чтобы пойти с конца строки

		for (int i = index; i >= 0; i--)
		{
			if (ar[i] == str5.ar[0])
			{
				flag = true;
				for (int j = 1; j < length2; j++)
				{
					if (ar[i + j] != str5.ar[j])
					{
						flag = false;
						break;
					}
				}
				if (flag == true) return i;
			}
		}
		return -1;
	}

	//Искать справа в исходной строке подстроку, равную первым нескольким символам исходной строки
	int rfind(String& str5, int index, int quant)
	{
		int length1 = size();
		int length2 = str5.size();
		bool flag;

		index = length1 - index; //Чтобы пойти с конца строки
		
		if (index == length1) index--;//Если индекс после 564 строки == 0, чтобы начать поиск с конца строки

		if (quant > length2) quant = length2;
		if (quant < 0) quant = 0;

		for (int i = index; i >= 0; i--)
		{
			if (ar[i] == str5.ar[0])
			{
				flag = true;
				for (int j = 1; j < quant; j++)
				{
					if (ar[i + j] != str5.ar[j])
					{
						flag = false;
						break;
					}
				}
				if (flag == true) return i;
			}
		}
		return -1;
	}

	//13 Ищет в исходной строке первое появление любого из символов другой строки
	int find_first_of(String& str6, int index = 0)
	{
		int length1 = size();
		int length2 = str6.size();

		index = checkIndex(index, length1);

		for (int i = index; i < length1; i++)
		{
			for (int j = 0; j < length2; j++)
			{
				if (ar[i] == str6.ar[j])
				{
					//cout << "The searching symbol is: " << ar[i];
					return i;
				}
			}
		}
		return -1;
	}

	//14 Ищет в исходной строке последнее появление любого из символов другой строки
	int find_last_of(String& str, int index = 0)
	{
		int length1 = size();
		int length2 = str.size();

		if (index < 0) index = 0;

		index = checkIndex(index, length1);

		for (int i = length1 - 1; i >= index; i--)
		{
			for (int j = 0; j < length2; j++)
			{
				if (ar[i] == str.ar[j]) return i;
			}
		}
		return -1;

	}

	//15 Ищет в исходной строке первое появление символа, отличного от символов другой строки
	int find_first_not_of(String& str, int index = 0)
	{
		int length1 = size();
		int length2 = str.size();
		bool flag;

		index = checkIndex(index, length1);

		for (int i = index; i < length1; i++)
		{
			flag = true;
			for (int j = 0; j < length2; j++)
			{
				if (ar[i] == str.ar[j])
				{
					flag = false;
					break;
				}
			}
			if (flag) return i;
		}
		return -1;
	}

	//16 Ищет в исходной строке последнее появление символа, отличного от символов другой строки
	int find_last_not_of(String& str, int index = 0)
	{
		int length1 = size();
		int length2 = str.size();
		bool flag;

		if (index < 0) index = 0;

		index = checkIndex(index, length1);

		for (int i = length1 - 1; i >= 0; i--)
		{
			flag = true;
			for (int j = 0; j < length2; j++)
			{
				if (ar[i] == str.ar[j])
				{
					flag = false;
					break;
				}
			}
			if (flag) return i;
		}
		return -1;
	}

	//17 Возвращает указатeль на область памяти, в которой хранятся символы строки, возвращает значение типа char*
	char* c_str()
	{
		return ar;
	}
};


