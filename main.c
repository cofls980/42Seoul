#include "push_swap.h"

/**
 * ?���? ??�소?�� ?��?��
 * ?��중에 추�???��줘야 ?�� 것들
 * - 메모�? ?��?�� ?�� ?��?��?��
 * - (o)?��?���? ?��?���? ?��?��?���? ?��?���? 그냥 ?��무것?�� 출력?��?���? ?��?��(?��?�� 1�? ?��?��?��?��?��?�� ?��?��)?��?��?�� 문자?�� ?��?��?���? ?��?��처리
 * - (o)?��?���? ?��?�� ?��?��?�� ?��?��처리
 * - (o)-2147483648 ~ 2147483647 int 범위?��?�� ?��?��?��?��?��
 * - (o)만약 "1 2 3" ?�� ?��?��?���? ?��?��?�� 1, 2, 3?�� ?��?���??���? ft_split() ?�� ?��?��?�� 공백 기�???���? 분리?��?��?��?�� �? ?��?��?��?��?��.
 * - (o)(-)?�� 고려?��줘야?��
 * - (o)?��?�� 중복 처리 ?��?��처리
 * - (o)?��?��처리?�� "Error\n" 출력
 * - 3�? ?��?��?���? 2 or 3�? instruction?�� ?��????��?��
 * - 5�? ?��?��?���? 최�?? 12�? instruction?�� ?��????��?��
 *      ?�� 경우 5�? �? 중간값을 ?��?��?��?�� 구하�? ?���? 기�???���? 중간값보?�� ?��거나 같�?? 값�?? ?��?�� ?��?��?��?�� rotate�? ?��?��?���?, ?��??? 값�?? ?���? ?��?��?���? ?��긴다.
 *      ?�� ?��, ?��?���??�� 개수�? 2개�?? ?���? 멈추�?, ?��?��(a기�??) ?��?��?�� ?��?��?�� ?��, ?���? ?��?��?�� ?��?��?���? ?��?��?��?��?���? ?��?���? ?��긴다. 
 * - 100�? ?��리면 700�? ?��?���? 결과�? ?��????�� 좋음
 * - 500�? ?��리면 5500�? ?��?���? 결과�? ?��????�� 좋음
 */
//15243
void    display(char *command, char stack_name)
{
    int i;

    i = 0;
    while (command[i])
    {
        write(1, &command[i], 1);
        i++;
    }
    if (stack_name)
        write(1, &stack_name, 1);
    write(1, "\n", 1);
}

int    is_valid(char **argv, t_list **st, int argc)
{
    char **str;
    int j;
    long long num;

    while (--argc > 0)
    {
        str = ft_split(argv[argc], ' ');
        j = ft_cnt(str);
        while (--j >= 0)
        {
            if (!is_number(str[j]))
                break;
            num = make_number(str[j]);
            if (num > 2147483647 || num < -2147483648)
                break;
            stack_push(st, new_item(num));
        }
        free_str(str);
        if (j != -1)
            break;
    }
    if (argc == 0)
        return (1);
    return (0);
}

int count_params(t_list **st)
{
    t_list *tmp;
    int cnt;

    cnt = 0;
    tmp = (*st);
    while (tmp)
    {
        cnt++;
        tmp = tmp->next;
        if (tmp == (*st))
            break;
    }
    return (cnt);
}

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;
    int count_param;
    int cnt;
    
    if (argc == 1)
        return (0);
    a = NULL;
    b = NULL;
    if (!is_valid(argv, &a, argc) || is_duplicated(&a))
    {
        display("Error", 0);
        free_stack(&a, &b);
        exit(1);
    }
    cnt = 0;
    count_param = count_params(&a);
    atob(&a, &b, count_param, &cnt);
    //printf("a: ");print_all(&a);
    //printf("b: ");print_all(&b);
    //printf("cnt: %d\n", cnt);
    free_stack(&a, &b);
    return (0);
}