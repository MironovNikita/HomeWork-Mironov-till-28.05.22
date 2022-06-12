#pragma once
class String
{
private:
	char* ar = new char[0];
	
	//�������� �������
	int checkIndex(int index, int size)
	{
		if (index > size) return size;
		else return index;
	}
	//�������� ���������� ����� �������
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

	//���������� ��������� ��� �������� ����� ������
	void operator = (String& str)
	{
		this->ar = str.ar;
	}

	//���������� (It's working! ^-^)
	~String()
	{
		cout << endl << "Delete: " << this << endl;
		delete[]ar;
	}

	//����� ������
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

	//1 ���������� ����� ������
	int size()
	{
		int size = 0;
		for (int i = 0; ar[i] != '\0'; i++)
		{
			size++;
		}
		return size;
	}

	//2 �������� ����� ������
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

	//3 ������� ������, ��� ���������� ������
	void clear()
	{
		char* buf = new char[1]{ "" };
		buf[0] = '\0';
		delete[]ar;
		ar = buf;
	}

	//4 ���������� true, ���� ������ �����, false - ���� ���
	bool empty()
	{
		int length = size();
		if (length == 0) return true;
		else return false;
	}

	//5 ��������� � ����� ������ ������ (���������� � ����� ���������� ���� char)
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

	//6 ��������� � ����� ������ ��������� ��������, ������ ������ ��� �������� ������ ������. ����� ��������� �������� ������
	//���������� ���������� ��������
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

	//��������� � ����� ������ ���������� ������ ������
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

	/*��������� � ����� ������ ���������� ������ ������, ������� � �������, �������� �������� ������, � �������� ����������� ���-
	�����. ���� ���������� �� �������� ������� �������� ������, ��� �������, ��������� ��� ���������� �� ������ ������ �������.*/
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

	//7 �������� �� ������ � �����. ����� ��������� ���������:
	//������� �� �������� ������ ���������� �������� � ������� � �� �����
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

	//������� �� ������ � ������� � �������� ����������� ���������� ���������
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

	//8 ��������� � �������� ������ ��������� ��������, ������ ������ ��� �������� ������ ������.
	//�������� ��������� ���������� ��������, �� ��������� ����������.
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

	//�������� ���������� ������ ������ � ������ � �������
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

	//�������� ���������� ������ ������ � ������ � ������� ������, ��������� ������ � ���������� �������� ������
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

	//9 ���������� ��������� ��� �������� �������� ������
	//���������� ��������� �������� ������ ������� � ������� � �� �����
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

	//���������� ��������� �������� ������ ������� ������� � ����������� ���������� ��������
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

	//10 �������� �������� ������ �� ��������� ������ ��������, ������ ������ ��� �������� ������ ������
	//�������� ����������� ���������� ���������� �������� ������ ������������ ��������� �������� � ������� �������� ������ 
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

	//�������� ���������� ������ ������ ������ ��������� ��������, ������� ����� ������� � ������� �������� ������ 
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

	//�������� ��������� �������� ������ ������ � ������������ ������� ������ ��������� ��������, ������� ����� ������� � ������� �������� ������ 
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

	//11 ���� � ������ ������ ������ ��������� ������ ������. ������������ ������ ������� �������, ������� � �������� ����� ��� ���������, ������ �������� ������
	//������ ������ ���������� ������ ������� � �������. ���� �� �� �����, �� ����� �������������� � ������
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

	//������ � �������� ������ ���������, ������ ������ ���������� �������� �������� ������
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
				//����� ��������� �� ��, ��� ������������� ������, ��� ����� ���-�� ������� ���������
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

	//12 ���� ��������� ��������� ��������� ("������ �����")
	//������ ������ ���������� ������ ������� � ������� (� �����)
	int rfind(String& str5, int index = 0)
	{
		int length1 = size();
		int length2 = str5.size();
		bool flag;
		index = length1 - index; //����� ����� � ����� ������

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

	//������ ������ � �������� ������ ���������, ������ ������ ���������� �������� �������� ������
	int rfind(String& str5, int index, int quant)
	{
		int length1 = size();
		int length2 = str5.size();
		bool flag;

		index = length1 - index; //����� ����� � ����� ������
		
		if (index == length1) index--;//���� ������ ����� 564 ������ == 0, ����� ������ ����� � ����� ������

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

	//13 ���� � �������� ������ ������ ��������� ������ �� �������� ������ ������
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

	//14 ���� � �������� ������ ��������� ��������� ������ �� �������� ������ ������
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

	//15 ���� � �������� ������ ������ ��������� �������, ��������� �� �������� ������ ������
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

	//16 ���� � �������� ������ ��������� ��������� �������, ��������� �� �������� ������ ������
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

	//17 ���������� ������e�� �� ������� ������, � ������� �������� ������� ������, ���������� �������� ���� char*
	char* c_str()
	{
		return ar;
	}
};


