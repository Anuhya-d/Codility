

class baseClass 
{
public:
	virtual double calculatePay()=0;
	virtual void getEmployeeDetails()=0;
	~baseClass() = default;
};

class Employee:public baseClass
{
public:
	string m_empName;
	int m_empId;
	int m_leavesTaken;
	float m_salary;
	float m_salMonth;
	int m_nProjects;

	Employee() = default;
	Employee(string empname, int empId, int letaken, float salary) :m_empName(empname),m_empId(empId), m_leavesTaken(letaken),m_salary(salary)// baseClass(empId), baseClass(letaken), baseClass(salary)
	{
	}
	~Employee()
	{
		cout << "destructor called here" << endl;
	}
	double calculatePay()
	{
		double val = (30 - m_leavesTaken)*m_salary;
		return val;
	}
	void getEmployeeDetails()
	{
		cout << "employeeName:" << m_empName << " employeeI: " << m_empId << " netSalary:" << calculatePay() << endl;;
	}
};

class Managerclass :public baseClass
{
private:
	string m_name;
	int m_empId;
	int m_fsalary;
	int m_nprojects;
	int bonus{ 2000 };
public:
	Managerclass() = default;
	Managerclass(string name, int empId, int fsalary, int nprojects) :m_name(name), m_empId(empId), m_fsalary(fsalary), m_nprojects(nprojects)
	{ }
	double calculatePay()
	{
		double val = m_fsalary + m_nprojects * bonus;
		return val;
	}
	
	void getEmployeeDetails()
	{
		cout << "employeeName:" << m_name << " employeeID: " << m_empId << " netSalary:" << calculatePay() << endl;;
	}
};

void getEmployeesDetails(baseClass *p)
	{
		p->getEmployeeDetails();
	}
	
int main()
{
	baseClass *p = new Employee("A", 101, 2, 3000.0);
	getEmployeesDetails(p);
	baseClass *p1 = new Employee("B", 1, 200, 3);
	getEmployeesDetails(p1);
	baseClass *p2 = new Employee("C", 2, 1800, 6);
	getEmployeesDetails(p2);
	baseClass *p3 = new Managerclass("X", 3, 8000, 2);
	getEmployeesDetails(p3);
	baseClass *p4 = new Managerclass("Y", 4, 7000, 3);
	getEmployeesDetails(p4);
return 0;
}	
