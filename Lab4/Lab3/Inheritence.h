#pragma once
#define iLikeIt		true
#define iDontLikeIt false

class product							// Абстрактный класс
{
	public:
		class inside {
		public:
			void inside_method(product* product)	// С помощью данного метода мы можем вызвать
			{										// метод одного производного класса из другого
				product->information();
			}
		}product_;
		virtual void toConsole() = 0;	// Чисто   виртуальные   функции   для 
		virtual void information() = 0;	// переопределения в производных классах  
};

class Pomelo  : virtual protected product
{
	private:
		//friend void Orange::Checking(Pomelo&);		// НИ РАБОТАИТ!!! дружественная функция, которая определена в классе Orange
		static int amountOfClasses;	// Статическая переменная для подсчета количества объетов класса
		const char* name = "Pomelo";
		int	 cost;					// Цена
		int	 amount;				// Количество на складе
		int	 shelfLife;				// Срок годности в часах
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
		bool DoYouLikeIt;			// Нравится ли вам данный продукт (true/false) 
		
};

class Orange : virtual public product
{
	private:
		int	 cost;					// Цена
		int	 amount;				// Количество на складе
		int	 shelfLife;				// Срок годности
		const char* name = "Orange";
	public:
		//void Orange::Checking(Pomelo& pomelo);
		Orange();
		Orange(int a, int b, int c, bool d);
		void information() override;		// Переопределение(не перегрузка) метода базового класса
		void toConsole() override;
	protected:
		bool DoYouLikeIt;
};

class Grapefruit : public Pomelo,  public Orange
{
	private:
		const char* name = "Grapefruit";	
		int DeliciousMark;					// Оценка вкуса грейпфрута ( от 1 до 10 )
	public:
		friend class Inspector;				// Все методы класса Inspector дружественные по отношению к данному классу
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
			std::cout <<"Мы получили доступ к приватному полю  !!! Оценка : "<<  product->DeliciousMark << std::endl << std::endl;
		}
};

class Curator
{
	public:
		void iCanModify(Grapefruit*  product)
		{
			std::cout << "Обнуление оценки продукта Grapefruit" << std::endl << std::endl;
			product->DeliciousMark = 0;
		}
};

class Printer			// Печать информации об объектах
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
//	cout << "Дружественная функция " <<  endl;
//}
