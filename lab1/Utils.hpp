//
// Created by gc on 16-9-16.
//

#ifndef LAB1_UTILS_HPP
#define LAB1_UTILS_HPP
#endif //LAB1_UTILS_HPP

#include "mongoose.h"

static const int http_200_response = 200;
static const int http_204_response = 204;
static const int http_400_response = 400;


static int has_prefix(const struct mg_str *uri, const struct mg_str *prefix) {
    return uri->len > prefix->len && memcmp(uri->p, prefix->p, prefix->len) == 0;
}

static int is_equal(const struct mg_str *s1, const struct mg_str *s2) {
    return s1->len == s2->len && memcmp(s1->p, s2->p, s2->len) == 0;
}
