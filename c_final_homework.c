#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string_pair
{
  char *src;
  char *dst;
} String_pair;

struct string_pair* str_pair_alloc(int src_size);
void str_pair_free(struct string_pair* str_pair);
void str_pair_copy(struct string_pair* str_pair);
int  str_pair_str_length(char* c);
void str_pair_copy_in_reverse_order(struct string_pair* str_pair);
void str_cpy(char *dst, char *src);
void str_reverse_cpy(char *dst, char *src);

int main(void)
{
  String_pair *pair = str_pair_alloc(10);
  
  str_cpy(pair->src, "hello");
  str_pair_copy_in_reverse_order(pair);

  printf("%s \n", pair->dst);

  str_pair_free(pair);
  return 0;
}

String_pair * str_pair_alloc(int src_size)
{
  String_pair *pString_pair;
  pString_pair = (String_pair *)malloc(sizeof(String_pair));
  pString_pair->src = (char *)malloc(src_size);
  pString_pair->dst = (char *)malloc(src_size);
  return pString_pair;
}

void str_pair_free(String_pair *str_pair)
{
  if (str_pair == NULL) return;
  if (str_pair->src != NULL) free(str_pair->src);
  if (str_pair->dst != NULL) free(str_pair->dst);
  free(str_pair);
  str_pair = NULL;
}

void str_pair_copy(struct string_pair *str_pair)
{
  str_cpy(str_pair->dst, str_pair->src);
}

void str_cpy(char *dst, char *src)
{
  while ((*dst++ = *src++) != 0)
    ;
}

int str_pair_str_length(char *c)
{
	int i = 0;
	char *p = (char *)c;
	while (*p++ != 0)
		i++;
	return i;
}

void str_pair_copy_in_reverse_order(struct string_pair* str_pair)
{
	str_reverse_cpy(str_pair->dst, str_pair->src);
}

void str_reverse_cpy(char *dst, char *src)
{
	int l = 0;
	while (*src != 0)
		++src,
		++l;
	for (;l>=0;l--)
		*dst++ = *--src;
}