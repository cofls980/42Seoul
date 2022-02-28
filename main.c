#include "push_swap.h"

/**
 * ?λΈ? ??΅μ?Έ ?¬?©
 * ?μ€μ μΆκ???΄μ€μΌ ?  κ²λ€
 * - λ©λͺ¨λ¦? ?? ? ??Ό?¨
 * - (o)?«?κ°? ?Έ?λ‘? ?€?΄?€μ§? ??Όλ©? κ·Έλ₯ ?λ¬΄κ²? μΆλ ₯??κ³? ??(?«? 1κ°? ?€?΄???? ??Ό)? ? ¬? λ¬Έμ?΄ ?€?΄?€λ©? ??Έμ²λ¦¬
 * - (o)?«?κ°? ?? ?Έ?? ??Έμ²λ¦¬
 * - (o)-2147483648 ~ 2147483647 int λ²μ?΄? ?«??¬?Ό?¨
 * - (o)λ§μ½ "1 2 3" ?΄ ?? ₯?λ©? ?€?? 1, 2, 3?΄ ?€?΄κ°??λ‘? ft_split() ? ?΄?©?΄ κ³΅λ°± κΈ°μ???Όλ‘? λΆλ¦¬?΄?Ό??¨ κ±? ???΅??€.
 * - (o)(-)? κ³ λ €?΄μ€μΌ?¨
 * - (o)?«? μ€λ³΅ μ²λ¦¬ ??Έμ²λ¦¬
 * - (o)??Έμ²λ¦¬? "Error\n" μΆλ ₯
 * - 3κ°? ?€?΄?€λ©? 2 or 3κ°? instruction?΄ ?????Ό?¨
 * - 5κ°? ?€?΄?€λ©? μ΅λ?? 12κ°? instruction?΄ ?????Ό?¨
 *      ?΄ κ²½μ° 5κ°? μ€? μ€κ°κ°μ ????¬ κ΅¬νκ³? ?΄λ₯? κΈ°μ???Όλ‘? μ€κ°κ°λ³΄?€ ?¬κ±°λ κ°μ?? κ°μ?? ??¬ ?€??? rotateλ₯? ?€??κ³?, ???? κ°μ?? ?€λ₯? ?€??Όλ‘? ?κΈ΄λ€.
 *      ?΄ ?, ??΄κ°?? κ°μκ°? 2κ°κ?? ?λ©? λ©μΆκ³?, ??¬(aκΈ°μ??) ?€?? ? ? ¬? ?, ?€λ₯? ?€?? ? ? ¬?κ³? ??¬?€??Όλ‘? ?«?λ₯? ?κΈ΄λ€. 
 * - 100κ°? ?λ¦¬λ©΄ 700κ°? ??κ°? κ²°κ³Όλ‘? ?????Ό μ’μ
 * - 500κ°? ?λ¦¬λ©΄ 5500κ°? ??κ°? κ²°κ³Όλ‘? ?????Ό μ’μ
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