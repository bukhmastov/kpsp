#include "static.h"
#include <QString>
#include <QChar>

int Static::scoreInitial = 50;
int Static::score4quetion = 2;
int Static::score4task = 1;
QString Static::messageAnswerRight = "Ответ верный (+2 балла)";
QString Static::messageAnswerWrong = "Ответ неверный (-2 балла)";

QString Static::getMSequence(/* polynom x^3+x+1 = 1011 */QString poly, int n) {
    QString args;
    for (int i = 0; i < poly.size() - 1; i++) {
        args.append("1");
    }
    return getMSequence(poly, args, n);
}

QString Static::getMSequence(/* polynom 1+x+x^3 = 1101 */QString poly, QString args, int n) {
    QString mSeg;
    mSeg.reserve(n);
    mSeg.append(args);
    poly.chop(1);
    for (int i = args.size(); i < n; i++) {
        int sum = 0;
        for (int j = 0; j < args.size(); j++) {
            if ((poly.at(args.size() - j - 1) == QChar('1')) && (mSeg.at(i - j - 1) == QChar('1'))) {
                sum++;
            }
        }
        mSeg.append(QString::number(sum % 2));
    }
    mSeg.squeeze();
    return mSeg;
}

QString Static::getXOR(QString p1, QString p2) {
    QString p12;
    for (int i = 0; i < p1.size(); i++) {
        p12.append(p1.at(i) == p2.at(i) ? "0" : "1");
    }
    return p12;
}

QString Static::getReadablePolynom(QString poly) {
    QString readable = "";
    int size = poly.size();
    for (int i = size - 1; i >= 0; i--) {
        if (poly.at(i) == QChar('1')) {
            if (!readable.isEmpty()) {
                readable += "+";
            }
            if (i == 0) {
                readable += "1";
            }
            if (i == 1) {
                readable += "x";
            }
            if (i > 1) {
                readable += "x<sup>" + QString::number(i) + "</sup>";
            }
        }
    }
    return readable;
}

std::vector<int> Static::getPAKF(QString f, int n) {
    std::vector<int> rm;
    for (int i = 0; i < n + 1; i++) {
        rm.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        QString fShift = "";
        for (int j = i; j < n + i; j++) {
            fShift.append(f.at(j % n));
        }
        int q = 0;
        for (int j = 0; j < n; j++) {
            if (f.at(j) == fShift.at(j)) {
                q++;
            }
        }
        rm[i] = 2 * q - n;
    }
    rm[n] = rm.at(0);
    return rm;
}

std::vector<int> Static::getAAKF(QString f, int n) {
    std::vector<int> rm;
    for (int i = 0; i < n + 1; i++) {
        rm.push_back(0);
    }
    for (int i = 0; i < n + 1; i++) {
        QString fShift = "";
        for (int j = 0; j < i; j++) {
            fShift.append("-");
        }
        for (int j = i; j < n; j++) {
            fShift.append(f.at(j));
        }
        int q = 0;
        int g = 0;
        for (int j = 0; j < n - 1; j++) {
            if (i + j > n - 2) {
                break;
            }
            if (f.at(j) == fShift.at(i + j)) {
                q++;
            } else {
                g++;
            }
        }
        rm[i] = q - g;
    }
    return rm;
}
