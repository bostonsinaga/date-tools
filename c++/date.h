#ifndef __DATE_TOOLS__DATE_H__
#define __DATE_TOOLS__DATE_H__

class Date {
public:
    Date() {}

    Date(std::string dateStr) {

        int dateDex = 0;
        std::string dmy_str[] = {"", "", ""};

        for (int i = 0; i < dateStr.length(); i++) {
            if (dateStr[i] == '/' || dateStr[i] == '-') {
                if (dateDex == 2) break;
                dateDex++;
            }
            else if (isChANum(dateStr[i])) {
                dmy_str[dateDex].push_back(dateStr[i]);
            }
        }

        int dmy_int[3];

        // convert string to int
        for (int i = 0; i < 3; i++) {
            dmy_int[i] = std::stoi(dmy_str[i]);
        }

        /** Normalize Date */

        day = std::abs(dmy_int[0]);
        month = std::abs(dmy_int[1]);
        year = std::abs(dmy_int[2]);

        if (month > 12) {
            year += std::floor(month / 12);
        }

        if (month != 0) {
            month %= 12;
            if (month == 0) month = 12;
        }

        Model::normalizeDay(day, month, year);
    }

    int day = 0, month = 0, year = 0;
};

#endif // __DATE_TOOLS__DATE_H__