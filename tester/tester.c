#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TEST(func, expected, ...) if (func(__VA_ARGS__) == expected) printf("%s: [OK]\n", #func); else printf("%s: [FAIL]\n", #func);
void test_basic_functions(void)
{
    TEST(ft_isalpha, 1, 'A')
    TEST(ft_isdigit, 1, '1')
    TEST(ft_isalnum, 1, 'a')
    TEST(ft_isascii, 1, 65)
    TEST(ft_isprint, 1, 97)
    TEST(ft_strlen, 5, "Hello")
    TEST(ft_toupper, 'A', 'a')
    TEST(ft_tolower, 'a', 'A')
    TEST(ft_atoi, 123, "123")

    void *memset_result = malloc(5);
    memset(memset_result, 'A', 4);
    ((char *)memset_result)[4] = '\0';
    TEST(strcmp, 0, memset_result, "AAAA")
    free(memset_result);

    char bzero_test[5] = "AAAA";
    ft_bzero(bzero_test, 4);
    TEST(strcmp, 0, bzero_test, "\0\0\0\0")

    char memcpy_dst[5];
    TEST(memcpy, memcpy_dst, memcpy_dst, "ABCD", 5)
    TEST(strcmp, 0, memcpy_dst, "ABCD")

    char memmove_dst[5] = "ABCD";
    TEST(memmove, memmove_dst + 1, memmove_dst + 1, memmove_dst, 3)
    TEST(strcmp, 0, memmove_dst + 1, "ABC")

    char strlcpy_dst[6];
    TEST(ft_strlcpy, 5, strlcpy_dst, "Hello", sizeof(strlcpy_dst))
    TEST(strcmp, 0, strlcpy_dst, "Hello")

    char strlcat_dst[10] = "Hello";
    TEST(ft_strlcat, 11, strlcat_dst, " world", sizeof(strlcat_dst) - strlen(strlcat_dst))
    
    TEST(ft_strchr, (void *)&"Hello"[1], "Hello", 'e')
    TEST(ft_strrchr, (void *)&"Hello"[4], "Hello", 'o')
    TEST(ft_strncmp, 0, "Hello", "Hello", 5)
    TEST(ft_memchr, (void *)&"Hello"[4], "Hello", 'o', 5)
    TEST(ft_memcmp, 0, "Hello", "Hello", 5)
    TEST(ft_strnstr, (void *)&"Hello world"[6], "Hello world", "world", 11)

    void *calloc_result = ft_calloc(5, sizeof(char));
    TEST(memcmp, 0, calloc_result, "\0\0\0\0\0", 5)
    free(calloc_result);

    char *strdup_result = ft_strdup("Hello");
    TEST(strcmp, 0, strdup_result, "Hello")
    free(strdup_result);
}

// Helper function for ft_strmapi test
char test_strmapi(unsigned int i, char c)
{
    return (char)(c + i);
}

// Helper function for ft_striteri test
void test_striteri(unsigned int i, char *c)
{
    *c = (char)(*c + i);
}

void test_additional_functions(void)
{
    // ft_substr
    char *substr_result = ft_substr("Hello, world!", 0, 5);
    TEST(strcmp, 0, substr_result, "Hello");
    free(substr_result);

    // ft_strjoin
    char *strjoin_result = ft_strjoin("Hello", " world!");
    TEST(strcmp, 0, strjoin_result, "Hello world!");
    free(strjoin_result);

    // ft_strtrim
    char *strtrim_result = ft_strtrim("   Hello, world!   ", " ");
    TEST(strcmp, 0, strtrim_result, "Hello, world!");
    free(strtrim_result);

    // ft_split
    char **split_result = ft_split("Hello world", ' ');
    TEST(strcmp, 0, split_result[0], "Hello");
    TEST(strcmp, 0, split_result[1], "world");
    free(split_result[0]);
    free(split_result[1]);
    free(split_result);

    // ft_itoa
    char *itoa_result = ft_itoa(12345);
    TEST(strcmp, 0, itoa_result, "12345");
    free(itoa_result);

    // ft_strmapi
    char *strmapi_result = ft_strmapi("Hello", test_strmapi);
    TEST(strcmp, 0, strmapi_result, "Hfnos");
    free(strmapi_result);

    // ft_striteri
    char striteri_test[] = "Hello";
    ft_striteri(striteri_test, test_striteri);
    TEST(strcmp, 0, striteri_test, "Hfnos");

    // ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd
    // These functions write output to a file descriptor, so it's harder to test them directly.
    // You can, however, test them manually by observing the output they produce.
    ft_putchar_fd('A', 1);
    ft_putstr_fd("\nHello, world!", 1);
    ft_putendl_fd("\nHello, world!", 1);
    ft_putnbr_fd(12345, 1);
}

#ifdef BONUS

void free_content(void *content)
{
    free(content);
}

void double_content(void *content)
{
    int *ptr = (int *)content;
    *ptr *= 2;
}

t_list *duplicate_node(void *content)
{
    int *ptr = (int *)content;
    int *new_content = (int *)malloc(sizeof(int));
    *new_content = *ptr;
    return ft_lstnew(new_content);
}

void test_bonus_functions(void)
{
    printf("Testing bonus functions...\n");

    t_list *head = NULL;

    // Test ft_lstnew
    int content1 = 42;
    t_list *node1 = ft_lstnew(&content1);
    assert(node1->content == &content1);
    printf("ft_lstnew: [OK]\n");

    // Test ft_lstadd_front
    int content2 = 24;
    t_list *node2 = ft_lstnew(&content2);
    ft_lstadd_front(&head, node2);
    assert(head == node2);
    printf("ft_lstadd_front: [OK]\n");

    // Test ft_lstsize
    ft_lstadd_front(&head, node1);
    assert(ft_lstsize(head) == 2);
    printf("ft_lstsize: [OK]\n");

    // Test ft_lstlast
    t_list *last_node = ft_lstlast(head);
    assert(last_node == node2);
    printf("ft_lstlast: [OK]\n");

    // Test ft_lstadd_back
    int content3 = 13;
    t_list *node3 = ft_lstnew(&content3);
    ft_lstadd_back(&head, node3);
    last_node = ft_lstlast(head);
    assert(last_node == node3);
    assert(ft_lstsize(head) == 3);
    printf("ft_lstadd_back: [OK]\n");

    printf("Bonus functions tests passed!\n");
}

#endif

int main(void)
{
    printf("\n==================== BASIC FUNCTIONS ====================\n");
    test_basic_functions();
    printf("\n================== ADDITIONAL FUNCTIONS =================\n");
    test_additional_functions();
    printf("\n==================== EXTRA FUNCTIONS ====================\n");
    #ifdef BONUS
        test_bonus_functions();
    #else
        printf("Bonus functions are not available.\n");
    #endif
    printf("\n===============================================\n");
    
    return 0;
}
