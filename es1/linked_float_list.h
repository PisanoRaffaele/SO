#include "linked_list.h"
#pragma once

typedef struct ListFloatItem {
  ListItem listItem;
  float info;
} ListFloatItem;

float sumListFloat(ListHead* head);

ListHead *FloatPopulateFromMatrix(ListHead **matrix);
