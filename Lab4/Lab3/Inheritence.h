#pragma once
#define iLikeIt		true
#define iDontLikeIt false

class product							// ����������� �����
{
	public:
		class inside {
		public:
			void inside_method(product* product)	// � ������� ������� ������ �� ����� �������
			{										// ����� ������ ������������ ������ �� �������
				product->information();
			}
		}product_;
		virtual void toConsole() = 0;	// �����   �����������   �������   ��� 
		virtual void information() = 0;	// ��������������� � ����������� �������  
};

class Pomelo  : virtual protected product
{
	private:
		//friend void Orange::Checking(Pomelo&);		// �� ��������!!! ������������� �������, ������� ���������� � ������ Orange
		static int amountOfClasses;	// ����������� ���������� ��� �������� ���������� ������� ������
		const char* name = "Pomelo";
		int	 cost;					// ����
		int	 amount;				// ���������� �� ������
		int	 shelfLife;				// ���� �������� � �����
	public:
		void AMOUNTOFCLASSES();
		Pomelo() : cost(-1), amount(-1), shelfLife(-1) { amountOfClasses++; };
		Pomelo(int, int, int, bool);
		void setAmount(int);
		void setCost(int);
		void setShelfLife(int);
		void toConsole() override;
		void information() override;
		~Pomelo()
		{
			amountOfClasses--;
		}	 
	protected:
		bool DoYouLikeIt;			// �������� �� ��� ������ ������� (true/false) 
		
};

class Orange : virtual public product
{
	private:
		int	 cost;					// ����
		int	 amount;				// ���������� �� ������
		int	 shelfLife;				// ���� ��������
		const char* name = "Orange";
	public:
		//void Orange::Checking(Pomelo& pomelo);
		Orange();
		Orange(int a, int b, int c, bool d);
		void information() override;		// ���������������(�� ����������) ������ �������� ������
		void toConsole() override;
	protected:
		bool DoYouLikeIt;
};

class Grapefruit : public Pomelo,  public Orange
{
	private:
		const char* name = "Grapefruit";	
		int DeliciousMark;					// ������ ����� ���������� ( �� 1 �� 10 )
	public:
		friend class Inspector;				// ��� ������ ������ Inspector ������������� �� ��������� � ������� ������
		friend class Curator;
		Grapefruit() : Orange::Orange() { DeliciousMark = -1; };
		Grapefruit(int ccost, int aamount, int sshelLife, bool DoYou, int Mark) : Pomelo::Pomelo(ccost, aamount, sshelLife, DoYou)
		{
			DeliciousMark = Mark;
		};
		void toConsole() override;
		void information();
};

class Inspector
{
	public:
		void	iKnowAllAboutYou(Grapefruit* product)
		{ 
			std::cout <<"�� �������� ������ � ���������� ����  !!! ������ : "<<  product->DeliciousMark << std::endl << std::endl;
		}
};

class Curator
{
	public:
		void iCanModify(Grapefruit*  product)
		{
			std::cout << "��������� ������ �������� Grapefruit" << std::endl << std::endl;
			product->DeliciousMark = 0;
		}
};

class Printer			// ������ ���������� �� ��������
{
	public:
		void iAmPrinting(Orange* product)
		{
			product->toConsole();
		};
		void iAmPrinting(Grapefruit* product)
		{
			product->toConsole();
		};	
		void iAmPrinting(Pomelo* product)
		{
			product->toConsole();
		};
};

//void Orange::Checking(Pomelo& pomelo)
//{
//	cout << "������������� ������� " <<  endl;
//}
