   if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->lines = lalloc();
        p->lines->lnum = linenum;
        p->lines->ptr = NULL;
        p->left = p->right = NULL;
    }