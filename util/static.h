#ifndef STATIC_H
#define STATIC_H

#include <QString>

class Static {
public:
    static int scoreInitial;
    static int score4quetion;
    static int score4task;
    static QString messageAnswerRight;
    static QString messageAnswerWrong;
    static QString getMSequence(QString, int);
    static QString getMSequence(QString, QString, int);
    static QString getXOR(QString, QString);
    static QString getReadablePolynom(QString);
    static std::vector<int> getPAKF(QString, int);
    static std::vector<int> getAAKF(QString, int);
    static QString alphabet01to11(QString);
    static QString alphabet11to01(QString);
    static QString sequence01to11(QString);
    static QString getDyadicShift(QString, int);
    static std::vector<int> getDPAKF(QString, int);
    static QString get3MSequence(int, int, int, int (*)(int, int));
    static std::vector<int> getLIPAKF(QString, int, int);
    static std::vector<std::pair<double, double>> getEVPAKF(QString, int);

private:
    static std::pair<double, double> two2euclide(int);
};

#endif // STATIC_H
