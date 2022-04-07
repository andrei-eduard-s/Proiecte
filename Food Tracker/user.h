#pragma once
class user {
public:
	//user(char='a', int=0, bool=0, double=0, double=0, double=0);
	inline enum BMI {under, average, over, obese, obese_extreme};
	inline enum activity{sedentary, light, moderate, intense};
	inline enum goal{ weight_loss, maintain, weight_gain};
	inline enum metabolism{fast, normal, slow};
	inline void setName(string);
	inline string getName();
	inline void setAge(int);
	inline int getAge();
	inline void setSex(bool);
	inline bool getSex();
	inline void setHeight(double);
	inline double getHeight();
	inline void setWeight(double);
	inline double getWeight();
	inline void setWeight_goal(double);
	inline double getWeight_goal();
	inline void setActivity(activity);
	inline int getActivity();
	inline void setGoal(goal);
	inline int getGoal();
	inline void setMetabolism(activity, BMI);
	inline int getMetabolism();
	inline void setBMI();
	inline int getBMI();
private:
	std::string name;
	int age;
	bool sex;
	double height;
	double weight;
	double weight_goal;
	activity user_activity;
	goal user_goal;
	metabolism user_metabolism;
	BMI user_BMI;
};
