#ifndef MOTOR_H
#define MOTOR_H


class Motor {
private:
    int id;
public:

    Motor(int id);
    void Trigger ();
    int getId() const;
};

#endif // MOTOR_H
