//
// Created by mbdin on 11/19/2019.
//
#include <iostream>
#include <deque>
#include <cstdlib>
#include <stdlib.h>

#ifndef OS_P3_FIFO_H
#define OS_P3_FIFO_H
using namespace std;

class FIFO {
private:
    int page_faults = 0, page_frames;
    deque<int> ref_string;
    bool found;

public:
    int get_faults() {
        return this->page_faults;
    }

    void set_frames(int page_frames) {
        this->page_frames = page_frames;
    }

    void set_string(deque<int> ref_string) {
        this->ref_string = ref_string;
    }

    void load_pages() {
        cout << "First In First Out" << endl;
        int page_table[page_frames];



        for (int i = 0; i < page_frames; i++) {
            page_table[i] = ref_string.front();
            page_faults++;
            ref_string.pop_front();
        }

        int index = 0, page;
        while (!ref_string.empty()) {
            page = ref_string.front();
            found = false;

            /*
            for (int i = 0; i < page_frames; i++) {
                cout << page_table[i] << endl;
            }
            cout << "--------------------" << endl;
            */

            for (int i = 0; i < page_frames; i++) {
                if (page == page_table[i]) {
                    found = true;
                    break;
                }
            }

            if (!found) { // not found (found == false)
                page_table[index % page_frames] = page;
                page_faults++;
                index++;
            }
            ref_string.pop_front();
        }
        cout << "Page faults -\t" << page_faults << endl << endl;
    }
};

#endif //OS_P3_FIFO_H
