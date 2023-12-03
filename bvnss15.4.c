#include <stdio.h>
#include <string.h>

struct Book
{
    int code;
    char title[50];
    char author[50];
    float price;
    char category[50];
};

void displayBook(struct Book arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Code: %d\n", arr[i].code);
        printf("Tên Sách: %s\n", arr[i].title);
        printf("Tác Giả: %s\n", arr[i].author);
        printf("Giá Tiền: %f\n", arr[i].price);
        printf("Thể Loại: %s\n", arr[i].category);
        printf("------------------\n");
    }
}

int searchBook(struct Book arr[], int size, char answer[50])
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].title, answer) == 0)
        {
            index = i;
        }
    }
    return index;
}
int searchBookByAuthor(struct Book arr[], int size, char answer[50]);

int main()
{
    struct Book book1 = {1, "Harry Potter", "JK Rowling", 20, "fiction"};
    struct Book book2 = {2, "Tôi thấy hoa vàng trên cỏ xanh", "Nguyễn Nhật Ánh", 20, "romance"};

    struct Book bookList[100] = {book1, book2};
    int currentSize = 2;

    int choice;
    while (choice != 6)
    {
        printf("************* MENU *************\n");
        printf("1. Thông tin sách trong cửa hàng\n");
        printf("2. Cập nhật thông tin sách (Thêm/Sửa/Xoá)\n");
        printf("3. Sắp xếp sách theo giá (Tăng/Giảm)\n");
        printf("4. Tìm kiếm sách (Tên tác giả)\n");
        printf("5. Tìm kiếm sách (Tên sách)\n");
        printf("6. Kết thúc chương trình\n");

        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            /* In ra toàn bộ thông tin về toàn bộ sách có trong cửa hàng */
            displayBook(bookList, currentSize);
            break;
        case 2:
            printf("************* Sub-menu *************\n");
            printf("2.1. Thêm sách mới vào cửa hàng\n");
            printf("2.2. Sửa thông tin sách\n");
            printf("2.3. Xoá sách khỏi cửa hàng\n");
            float subChoice;
            scanf("%f", &subChoice);
            fflush(stdin);

            if (subChoice == 2.1f)
            {
                // Thêm sách
                struct Book newBook;

                printf("Nhập vào code của sách\n");
                scanf("%d", &newBook.code);
                fflush(stdin);

                printf("Nhập vào tên của sách\n");
                gets(newBook.title);

                printf("Nhập vào tác giả của sách\n");
                gets(newBook.author);

                printf("Nhập vào giá của sách\n");
                scanf("%f", &newBook.price);
                fflush(stdin);

                printf("Nhập vào category của sách\n");
                gets(newBook.category);

                bookList[currentSize] = newBook;
                currentSize++;

                displayBook(bookList, currentSize);
            }
            else if (subChoice == 2.2f)
            {
                // Sửa thông tin sách
                char answer[100];
                printf("Nhập vào quyển sách bạn muốn chỉnh sửa: \n");
                gets(answer);

                int updateIndex = searchBook(bookList, currentSize, answer); // -1, index

                if (updateIndex != -1)
                {
                    printf("Nhập vào tên cập nhật của sách\n");
                    gets(bookList[updateIndex].title);

                    printf("Nhập vào tác giả mới của sách\n");
                    gets(bookList[updateIndex].author);

                    printf("Nhập vào giá mới của sách\n");
                    scanf("%f", &bookList[updateIndex].price);
                    fflush(stdin);

                    displayBook(bookList, currentSize);
                }
            }
            else if (subChoice == 2.3f)
            {
                // Xoá sách
                char answer[100];
                printf("Nhập vào quyển sách bạn muốn xoá: \n");
                gets(answer);

                int deleteIndex = searchBook(bookList, currentSize, answer); // -1, index

                if (deleteIndex != -1)
                {
                    // { book1, book2, book4, book5} ... }
                    for (int i = deleteIndex; i < currentSize; i++)
                    {
                        bookList[i] = bookList[i + 1];
                    }
                    currentSize--;
                    displayBook(bookList, currentSize);
                }
            }
            break;
        case 4:
        {
            // Sửa thông tin sách
            char answer[50];
            printf("Nhập vào quyển sách bạn muốn tìm kiếm: \n");
            gets(answer);
            int searchIndex = searchBook(bookList, currentSize, answer); // -1 || index
            if (searchIndex == -1)
            {
                printf("Không tìm thấy quyển sách mà bạn vừa nhập vào \n");
            }
            else
            {
                struct Book findBook = bookList[searchIndex];
                printf("Code: %d\n", findBook.code);
                printf("Tên Sách: %s\n", findBook.title);
                printf("Tác Giả: %s\n", findBook.author);
                printf("Giá Tiền: %f\n", findBook.price);
                printf("Thể Loại: %s\n", findBook.category);
                printf("------------------\n");
            }
            break;
        }
        case 5:
            // Giống hệt case 4
            break;
        default:
            if (choice == 6)
            {
                printf("Cảm ơn bạn đã dùng chương trình! Bye bye!!!!\n");
            }
            else
            {
                printf("Sai cú pháp, mời nhập lại!!!!\n");
            }
            break;
        }
    }

    return 0;
}
