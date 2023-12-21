﻿#include <iostream>
#include <string>

// Product class
class Pizza {
public:
	void setDough(const std::string& dough)
	{
		this->dough = dough;
	}
	void setSauce(const std::string& sauce)
	{
		this->sauce = sauce;
	}
	void setTopping(const std::string& topping)
	{
		this->topping = topping;
	}
	void setBottoming(const std::string& bottoming)
	{
		this->bottoming = bottoming;
	}
	void displayPizza() const
	{
		std::cout << "\nPizza with Dough: " << dough
			<< "\nSauce: " << sauce
			<< "\nTopping: " << topping;
		if (!bottoming.empty())	std::cout << "\nBottoming: " << bottoming;
		std::cout << "\n\n";
	}
private:
	std::string dough;
	std::string sauce;
	std::string topping;
	std::string bottoming;
};
// Abstract builder class
class PizzaBuilder {
public:
	virtual void buildDough() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;
	virtual void buildBottoming()
	{
		pizza.setBottoming("brak");
	}
	virtual Pizza getPizza() const = 0;
private:
	Pizza pizza;
};
// Concrete builder for a specific type of pizza
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
	void buildDough() override
	{
		pizza.setDough("Pan Dough");
	}
	void buildSauce() override
	{
		pizza.setSauce("Hawaiian Sauce");
	}
	void buildTopping() override
	{
		pizza.setTopping("Ham and Pineapple");
	}
	Pizza getPizza() const override { return pizza; }
private:
	Pizza pizza;
};
// Concrete builder for another my type of pizza :3
class KacperOlakPizzaBuilder : public PizzaBuilder {
public:
	void buildDough() override
	{
		pizza.setDough("ciasto od babci");
	}
	void buildSauce() override
	{
		pizza.setSauce("ketchup and passata potion");
	}
	void buildTopping() override
	{
		pizza.setTopping("pieczarki z pieczarkami");
	}
	void buildBottoming() override
	{
		pizza.setBottoming("pieniazek na szczescie");
	}
	Pizza getPizza() const override { return pizza; }
private:
	Pizza pizza;
};
// Concrete builder for another type of pizza
class SpicyPizzaBuilder : public PizzaBuilder {
public:
	void buildDough() override
	{
		pizza.setDough("Thin Dough");
	}
	void buildSauce() override
	{
		pizza.setSauce("Spicy Tomato Sauce");
	}
	void buildTopping() override
	{
		pizza.setTopping("Pepperoni and Jalapenos");
	}
	Pizza getPizza() const override { return pizza; }
private:
	Pizza pizza;
};
// Director class that orchestrates the construction
class Cook {
public:
	void makePizza(PizzaBuilder& builder)
	{
		builder.buildDough();
		builder.buildSauce();
		builder.buildTopping();
		builder.buildBottoming();
	}
};
int main()
{
	Cook cook;
	HawaiianPizzaBuilder hawaiianBuilder;
	cook.makePizza(hawaiianBuilder);
	Pizza hawaiianPizza = hawaiianBuilder.getPizza();
	hawaiianPizza.displayPizza();
	SpicyPizzaBuilder spicyBuilder;
	cook.makePizza(spicyBuilder);
	Pizza spicyPizza = spicyBuilder.getPizza();
	spicyPizza.displayPizza();

	KacperOlakPizzaBuilder cookslittlehelp;
	cook.makePizza(cookslittlehelp);
	Pizza Mypizza = cookslittlehelp.getPizza();
	Mypizza.displayPizza();

	return 0;
}