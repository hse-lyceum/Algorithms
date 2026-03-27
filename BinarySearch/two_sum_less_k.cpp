/*
 * Дан упорядоченный массив положительных чисел и некое число k.
 * Необходимо найти два таких элемента массива, что их сумма будет меньше k
 * и при этом она будет максимальной из всех возможных сумм. Если таких
 * элементов нет, необходимо вернуть -1
 *
 * LeetCode: https://leetcode.com/problems/two-sum-less-than-k/description/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// Методом двоичного поиска возвращаем индекс элемента, который максимально близок к ceil,
// но не равен ему. Для инициализации максимума передаём по умолчанию параметр abs_limit
int closestMaximum(vector<int>& v, int ceil, int abs_limit = 1000000) {
    int max = -abs_limit;
    int index = -1;
    int L = 0, R = static_cast<int>(v.size()) - 1;
    while (L <= R) {

        // если нашли элемент меньше ceil, пытаемся идти вправо
        if (const int mid = L + (R - L) / 2; v[mid] < ceil) {
            if (v[mid] > max) {
                max = v[mid];
                index = mid;
            }
            L = mid + 1;
        }
        // если нашли элемент больший, чем ceil, идём влево
        else {
            R = mid - 1;
        }
    }

    // если нашли такой элемент, возвращаем его индекс, иначе возвращаем -1
    if (max != abs_limit) {
        return index;
    }
    return -1;
}

// Ищем два элемента, которые в сумме дают максимальное число меньшее k
// Для каждого элемента ищем парный элемент, который приблежается к разности k и самого элемента
int twoSumLessThanK(vector<int>& nums, int k) {

    // сначала сортируем массив
    std::sort(nums.begin(), nums.end());

    // инициализируем конечный результат
    int result = -1;

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int diff = k - nums[i];

        // если элемент больше k, то для него не подобрать пару, поскольку все элементы положительные
        if (diff < 0) {
            continue;
        }

        // индекс потанциальной пары
        int other = closestMaximum(nums, diff);

        // если такой элемент есть и это не сам элемент
        if (other != -1 && other != i) {
            int sum_candidate = nums[i] + nums[other];
            if (sum_candidate > result) {
                result = sum_candidate;
            }
        }
    }
    return result;
}

int main() {
    vector<int> v;

    v = { 358, 898, 450, 732, 672, 672, 256, 542, 320, 573,423, 543, 591, 280, 399, 923, 920, 254,
           135, 952, 115, 536, 143, 896, 411, 722, 815, 635, 353, 486, 127, 146, 974, 495, 229, 21,
           733, 918, 314, 670, 671, 537, 533, 716, 140, 599, 758, 777, 185, 549 };
    cout << twoSumLessThanK(v, 1800) << endl; // 1794

    v =  { 254, 914, 110, 900, 147, 441, 209, 122, 571, 942, 136, 350, 160, 127, 178, 839, 201, 386,
          462, 45, 735, 467, 153, 415, 875, 282, 204, 534, 639, 994, 284, 320, 865, 468, 1, 838, 275,
          370, 295, 574, 309, 268, 415, 385, 786, 62, 359, 78, 854, 944 };

    cout << twoSumLessThanK(v, 200) << endl;  // 198
    cout << twoSumLessThanK(v, 1800) << endl; // 1798
    
    return 0;
}