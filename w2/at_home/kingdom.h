namespace westeros{
	struct Kingdom{
		char m_name[32];
		int m_population;
	};
	void display(Kingdom* tr);
	void display(Kingdom tr[], int count);
	void display(Kingdom tr[], int count,int minval);
	void display(Kingdom tr[], int count, const char name[]);
}