#pragma once

class product
{
	private:
		char nameOfProduct[20];
		int	 cost;
		int	 amount;
	public:
		product() : nameOfProduct("NULL"), cost(0), amount(0) {};
		product(char*, int, int);
		void information();
		void addProduct(int);
		void removeFromSale(int);
		~product()
		{
		}
};
class food_product final : public product
{
	private:
		int shelfLife;
	public:
		void information();
		food_product() : product::product()
		{
			shelfLife = 0;
		}
		int getLife()
		{
			return shelfLife;
		}
		food_product(char*, int, int, int);
		~food_product()
		{
		}
};




