#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct nlist{
    struct nlist *next;
    char *name;/*define name */
    char *defn;/* replacement text */
};

#define HASHSIZE 101
static struct nlist* hashtab[HASHSIZE];

char *strdup1(char *s);
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name,char *defn);
struct nlist *undef(char *name);

int main(int argc, char const *argv[])
{
    struct nlist *np,*p;
    np=install("key1","value1");
    //p=lookup("key1");
    undef("key1");
    p=lookup("key1");
    if(p!=NULL){
        printf("%s : %s\n",p->name,p->defn);
    }else{
        printf("not exist!\n");
    }
    return 0;
}

/*hash: form hash value for string s */
unsigned hash(char *s){
    unsigned hashval;
    for(hashval=0;*s!='\0';s++){
        hashval=*s +31*hashval;
    }
    return hashval %HASHSIZE;
}

/*loopup: look for s in hashtab */
struct nlist *lookup(char *s){
    struct nlist *np;
    
    for(np = hashtab[hash(s)];np!=NULL;np=np->next){
        if(strcmp(s,np->name)==0)
            return np;
    }
    return NULL;
}

/*install: put(name,defn) in hashtab */
struct nlist *install(char *name,char *defn){
    struct nlist *np;
    unsigned hashval;

    if((np=lookup(name))==NULL){
        np=(struct nlist *) malloc(sizeof(*np));
        if(np==NULL || (np->name = strdup1(name))==NULL)
            return NULL;
        hashval=hash(name);
        np->next=hashtab[hashval];
        hashtab[hashval]=np;
    }else  
        free((void *)np->defn);
    if((np->defn=strdup1(defn))==NULL)
        return NULL;
    return np;
}

/*undef: delete name in hashtab if exist*/
struct nlist *undef(char *name){
    struct nlist *np;
    unsigned hashval;
    if((np=lookup(name))==NULL){
        return NULL;
    }
    hashval=hash(name);
    hashtab[hashval]=np->next;
    return np;
}

char *strdup1(char *s){
    char *p;

    p = (char *) malloc(strlen(s)+1);
    if(p!=NULL)
     strcpy(p,s);
    return p;
}