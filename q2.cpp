class Employee:
    def __init__(self, name, id):
        self.name = name
        self.id = id

    def calculate_weekly_salary(self):
        pass

    def compute_health_care_contributions(self):
        pass

    def compute_vacation_days(self):
        pass


class Professional(Employee):
    def __init__(self, name, id, monthly_salary, vacation_days):
        super().__init__(name, id)
        self.monthly_salary = monthly_salary
        self.vacation_days = vacation_days

    def calculate_weekly_salary(self):
        return self.monthly_salary / 4

    def compute_health_care_contributions(self):
        return 0.05 * self.monthly_salary

    def compute_vacation_days(self):
        return self.vacation_days


class Nonprofessional(Employee):
    def __init__(self, name, id, hourly_rate, vacation_hours):
        super().__init__(name, id)
        self.hourly_rate = hourly_rate
        self.vacation_hours = vacation_hours

    def calculate_weekly_salary(self, hours_worked):
        return self.hourly_rate * hours_worked

    def compute_health_care_contributions(self, hours_worked):
        return 0.02 * self.calculate_weekly_salary(hours_worked)

    def compute_vacation_days(self, hours_worked):
        return self.vacation_hours * hours_worked // 80


p = Professional("John Smith", "1234", 5000, 20)
n = Nonprofessional("Jane Doe", "5678", 25, 80)

print(p.name)
print(p.calculate_weekly_salary())
print(p.compute_health_care_contributions())
print(p.compute_vacation_days())

print(n.name)
print(n.calculate_weekly_salary(40))
print(n.compute_health_care_contributions(40))
print(n.compute_vacation_days(40))

