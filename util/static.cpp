#include "static.h"
#include <QString>
#include <QChar>

int Static::scoreInitial = 50;
int Static::score4quetion = 2;
int Static::score4task = 1;
QString Static::messageAnswerRight = "Ответ верный (+2 балла)";
QString Static::messageAnswerWrong = "Ответ неверный (-2 балла)";

QString Static::getMSequence(/* polynom 1+x+x^3 = 1011 */QString poly, int n) {
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
    int size = p1.size() > p2.size() ? p1.size() : p2.size();
    for (int i = 0; i < size; i++) {
        p12.append(p1.at(i % p1.size()) == p2.at(i % p2.size()) ? "0" : "1");
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
        QString fs = ""; // сдвиг вправо на i знаков с заполнением левых символов
        for (int j = n - i; j < 2 * n - i; j++) {
            fs.append(f.at(j % n));
        }
        int q = 0;
        for (int j = 0; j < n; j++) {
            if (f.at(j) == fs.at(j)) {
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
    for (int i = 0; i < n; i++) {
        QString fs = ""; // сдвиг вправо на i знаков без заполнения передних символов
        for (int j = n - i; j < 2 * n - i; j++) {
            fs.append(j >= n ? f.at(j % n) : QChar('-'));
        }
        int q = 0;
        int g = 0;
        for (int j = n - i; j < 2 * n - i; j++) {
            if (j >= n) {
                if (f.at(j % n + i) == fs.at(j % n + i)) {
                    q++;
                } else {
                    g++;
                }
            }
        }
        rm[i] = q - g;
    }
    return rm;
}

QString Static::alphabet01to11(QString text) {
    if (text == "0") {
        return "+1";
    }
    if (text == "1") {
        return "-1";
    }
    return text;
}

QString Static::alphabet11to01(QString text) {
    if (text == "1" || text == "+1") {
        return "0";
    }
    if (text == "-1") {
        return "1";
    }
    return text;
}

QString Static::sequence01to11(QString text) {
    QString ret = "";
    for (int i = 0; i < text.size(); i++) {
        ret.append(QString(alphabet01to11(text.at(i))));
    }
    return ret;
}

QString Static::getDyadicShift(QString f, int s) {
    QString fds = "";
    if (s == 0) {
        return f;
    }
    for (int i = 0; i < f.size(); i += s * 2) {
        fds.append(f.mid(i + s, s));
        fds.append(f.mid(i, s));
    }
    return fds;
}

std::vector<int> Static::getDPAKF(QString f, int n) {
    std::vector<int> rm;
    for (int i = 0; i < n + 1; i++) {
        rm.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        std::vector<int> power;
        for (int bit = 0; bit < i; bit++) {
            int bin_power = 1 << bit;
            if (bin_power & i) {
                power.push_back(bin_power);
            }
        }
        QString ds = f;
        for (int j = power.size() - 1; j >= 0; j--) {
            ds = getDyadicShift(ds, power.at(j));
        }
        int q = 0;
        for (int j = 0; j < n; j++) {
            if (f.at(j) == ds.at(j)) {
                q++;
            }
        }
        rm[i] = 2 * q - n;
    }
    rm[n] = rm.at(0);
    return rm;
}

QString Static::get3MSequence(int c0, int c1, int n, int (*get)(int, int)) {
    QString mSeq;
    int c2;
    mSeq.append(QString::number(c0));
    mSeq.append(QString::number(c1));
    for (int i = 2; i < n; i++) {
        c2 = get(c1, c0) % 3;
        mSeq.append(QString::number(c2));
        c0 = c1;
        c1 = c2;
    }
    return mSeq;
}

std::vector<int> Static::getLIPAKF(QString f, int p, int n) {
    std::vector<int> rm;
    for (int i = 0; i < n + 1; i++) {
        rm.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        QString fs = ""; // сдвиг вправо на i знаков с заполнением левых символов
        for (int j = n - i; j < 2 * n - i; j++) {
            fs.append(f.at(j % n));
        }
        int d = 0;
        for (int j = 0; j < n; j++) {
            if (f.at(j) != fs.at(j)) {
                d++;
            }
        }
        rm[i] = (int) std::round((double) n - (double) ((4.0 / (double) p) * (double) d));
    }
    rm[n] = rm.at(0);
    return rm;
}

std::vector<std::pair<double, double>> Static::getEVPAKF(QString f, int n) {
    std::vector<std::pair<double, double>> rm;
    for (int i = 0; i < n + 1; i++) {
        rm.push_back(std::make_pair(0.0, 0.0));
    }
    for (int i = 0; i < n; i++) {
        QString fs = ""; // сдвиг вправо на i знаков с заполнением левых символов
        for (int j = n - i; j < 2 * n - i; j++) {
            fs.append(f.at(j % n));
        }
        for (int j = 0; j < n; j++) {
            int i1 = QString(fs.at(j)).toInt();
            int i2 = QString(f.at(j)).toInt();
            switch (i2) {
            case 1: i2 = 2; break;
            case 2: i2 = 1; break;
            }
            std::pair<double, double> f1 = Static::two2euclide(i1); // исходный сдвинутый
            std::pair<double, double> f2 = Static::two2euclide(i2); // дополненный статичный
            rm[i].first += f1.first * f2.first - f1.second * f2.second; // Re
            rm[i].second += f1.first * f2.second + f1.second * f2.first; // Im
        }
        rm[i].first = ((double) ((int) std::round((rm[i].first / n) * 1000))) / 1000;
        rm[i].second = ((double) ((int) std::round((rm[i].second / n) * 1000))) / 1000;
    }
    rm[n] = rm.at(0);
    return rm;
}

std::pair<double, double> Static::two2euclide(int i) {
    switch (i % 3) {
    case 0: return std::make_pair( 1.0,   0.0);
    case 1: return std::make_pair(-0.5,   sqrt(3) / 2.0);
    case 2: return std::make_pair(-0.5, - sqrt(3) / 2.0);
    }
}

std::vector<double> Static::getDLIPAKF(QString f, int p, int n) {
    std::vector<double> rm;
    for (int i = 0; i < n + 1; i++) {
        rm.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        std::vector<int> power;
        for (int bit = 0; bit < i; bit++) {
            int bin_power = 1 << bit;
            if (bin_power & i) {
                power.push_back(bin_power);
            }
        }
        QString ds = f;
        for (int j = power.size() - 1; j >= 0; j--) {
            ds = getDyadicShift(ds, power.at(j));
        }
        int d = 0;
        for (int j = 0; j < n; j++) {
            if (f.at(j) != ds.at(j)) {
                d++;
            }
        }
        rm[i] = ((double) ((int) std::round(((double) n - (double) ((4.0 / (double) p) * (double) d)) * 1000))) / 1000;
    }
    rm[n] = rm.at(0);
    return rm;
}

std::vector<std::pair<double, double>> Static::getDEVPAKF(QString f, int n) {
    std::vector<std::pair<double, double>> rm;
    for (int i = 0; i < n + 1; i++) {
        rm.push_back(std::make_pair(0.0, 0.0));
    }
    for (int i = 0; i < n; i++) {
        std::vector<int> power;
        for (int bit = 0; bit < i; bit++) {
            int bin_power = 1 << bit;
            if (bin_power & i) {
                power.push_back(bin_power);
            }
        }
        QString ds = f;
        for (int j = power.size() - 1; j >= 0; j--) {
            ds = getDyadicShift(ds, power.at(j));
        }
        for (int j = 0; j < n; j++) {
            int i1 = QString(ds.at(j)).toInt();
            int i2 = QString(f.at(j)).toInt();
            switch (i2) {
            case 1: i2 = 2; break;
            case 2: i2 = 1; break;
            }
            std::pair<double, double> f1 = Static::two2euclide(i1); // исходный сдвинутый
            std::pair<double, double> f2 = Static::two2euclide(i2); // дополненный статичный
            rm[i].first += f1.first * f2.first - f1.second * f2.second; // Re
            rm[i].second += f1.first * f2.second + f1.second * f2.first; // Im
        }
        rm[i].first = ((double) ((int) std::round((rm[i].first / n) * 1000))) / 1000;
        rm[i].second = ((double) ((int) std::round((rm[i].second / n) * 1000))) / 1000;
    }
    rm[n] = rm.at(0);
    return rm;
}

std::vector<int> Static::getPVKF(QString f1, QString f2, int n) {
    std::vector<int> rm;
    for (int i = 0; i < n + 1; i++) {
        rm.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        QString f2s = ""; // сдвиг вправо на i знаков с заполнением левых символов
        for (int j = n - i; j < 2 * n - i; j++) {
            f2s.append(f2.at(j % n));
        }
        int q = 0;
        for (int j = 0; j < n; j++) {
            if (f1.at(j) == f2s.at(j)) {
                q++;
            }
        }
        rm[i] = 2 * q - n;
    }
    rm[n] = rm.at(0);
    return rm;
}
