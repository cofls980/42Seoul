#include "push_swap.h"

/**
 * ?”ë¸? ??µì†Œ?Š¸ ?‚¬?š©
 * ?‚˜ì¤‘ì— ì¶”ê???•´ì¤˜ì•¼ ?•  ê²ƒë“¤
 * - ë©”ëª¨ë¦? ?ˆ„?ˆ˜ ?•ˆ ?‚˜?•¼?•¨
 * - (o)?ˆ«?žê°? ?¸?ˆ˜ë¡? ?“¤?–´?˜¤ì§? ?•Š?œ¼ë©? ê·¸ëƒ¥ ?•„ë¬´ê²ƒ?„ ì¶œë ¥?•ˆ?•˜ê³? ??ƒ„(?ˆ«?ž 1ê°? ?“¤?–´?™”?„?•Œ?„ ?™?¼)? •? ¬?œ ë¬¸ìž?—´ ?“¤?–´?˜¤ë©? ?˜ˆ?™¸ì²˜ë¦¬
 * - (o)?ˆ«?žê°? ?•„?‹Œ ?¸?ˆ˜?Š” ?˜ˆ?™¸ì²˜ë¦¬
 * - (o)-2147483648 ~ 2147483647 int ë²”ìœ„?‚´?˜ ?ˆ«?ž?—¬?•¼?•¨
 * - (o)ë§Œì•½ "1 2 3" ?´ ?ž…? ¥?˜ë©? ?Š¤?ƒ?— 1, 2, 3?´ ?“¤?–´ê°??„ë¡? ft_split() ?„ ?´?š©?•´ ê³µë°± ê¸°ì???œ¼ë¡? ë¶„ë¦¬?•´?•¼?œ?‹¨ ê±? ?•Œ?•˜?Šµ?‹ˆ?‹¤.
 * - (o)(-)?„ ê³ ë ¤?•´ì¤˜ì•¼?•¨
 * - (o)?ˆ«?ž ì¤‘ë³µ ì²˜ë¦¬ ?˜ˆ?™¸ì²˜ë¦¬
 * - (o)?˜ˆ?™¸ì²˜ë¦¬?Š” "Error\n" ì¶œë ¥
 * - 3ê°? ?“¤?–´?˜¤ë©? 2 or 3ê°? instruction?´ ?‚˜????•¼?•¨
 * - 5ê°? ?“¤?–´?˜¤ë©? ìµœë?? 12ê°? instruction?´ ?‚˜????•¼?•¨
 *      ?´ ê²½ìš° 5ê°? ì¤? ì¤‘ê°„ê°’ì„ ?ƒ?ƒ‰?•˜?—¬ êµ¬í•˜ê³? ?´ë¥? ê¸°ì???œ¼ë¡? ì¤‘ê°„ê°’ë³´?‹¤ ?¬ê±°ë‚˜ ê°™ì?? ê°’ì?? ?˜„?ž¬ ?Š¤?ƒ?—?„œ rotateë¥? ?‹¤?–‰?•˜ê³?, ?ž‘??? ê°’ì?? ?‹¤ë¥? ?Š¤?ƒ?œ¼ë¡? ?„˜ê¸´ë‹¤.
 *      ?´ ?•Œ, ?„˜?–´ê°??Š” ê°œìˆ˜ê°? 2ê°œê?? ?˜ë©? ë©ˆì¶”ê³?, ?˜„?ž¬(aê¸°ì??) ?Š¤?ƒ?„ ? •? ¬?•œ ?›„, ?‹¤ë¥? ?Š¤?ƒ?„ ? •? ¬?•˜ê³? ?˜„?ž¬?Š¤?ƒ?œ¼ë¡? ?ˆ«?žë¥? ?„˜ê¸´ë‹¤. 
 * - 100ê°? ?Œë¦¬ë©´ 700ê°? ?•„?ž˜ê°? ê²°ê³¼ë¡? ?‚˜????•¼ ì¢‹ìŒ
 * - 500ê°? ?Œë¦¬ë©´ 5500ê°? ?•„?ž˜ê°? ê²°ê³¼ë¡? ?‚˜????•¼ ì¢‹ìŒ
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