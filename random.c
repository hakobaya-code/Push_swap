/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:40:45 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/11 20:40:50 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_VALUES 100
#define MAX_VALUE 999

int main(int argc, char *argv[]) {
    int values[NUM_VALUES] = {0};
    int count = 0;

    // 乱数生成器の初期化
    srand((unsigned int)time(NULL));

    while (count < NUM_VALUES) {
        int randValue = rand() % (MAX_VALUE + 1);

        // 重複チェック
        int duplicate = 0;
        for (int i = 0; i < count; i++) {
            if (values[i] == randValue) {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate) {
            values[count++] = randValue;
        }
    }

    // 値の出力
    for (int i = 0; i < NUM_VALUES; i++) {
        printf("%d\n", values[i]);
    }

    return 0;
}
