#include <iostream>
#include <vector>

class BaseRetriever
{
public:
    using doc_t = int32_t;
    using docs_t = const std::vector<doc_t>;
    BaseRetriever()
    {
        std::cout << "BaseRetriever::BaseRetriever()" << std::endl;
    }

    //! Ранжирование документа.
    virtual void retrieve(doc_t doc) = 0;

    //! Сортировка итоговых документов.
    virtual void sort(docs_t& docs) = 0;

    virtual ~BaseRetriever()
    {
        std::cout << "BaseRetriever::~BaseRetriever()" << std::endl;
    }
};

class YoulaRetriever : public BaseRetriever
{
public:
    YoulaRetriever()
    {
        std::cout << "YoulaRetriever::YoulaRetriever()" << std::endl;
    }

    void retrieve(doc_t doc) override
    {
        std::cout << "YoulaRetriever::retrieve" << std::endl;
    }
    virtual void sort(docs_t& docs) {}
    ~YoulaRetriever()
    {
        std::cout << "YoulaRetriever::~YoulaRetriever()" << std::endl;
    }
};

class VideoRetriever : public BaseRetriever
{
public:
    VideoRetriever()
    {
        std::cout << "VideoRetriever::VideoRetriever()" << std::endl;
    }

    void retrieve(doc_t doc) override
    {
        std::cout << "VideoRetriever::retrieve" << std::endl;
    }

    virtual void sort(docs_t& docs) {}

    ~VideoRetriever() override
    {
        std::cout << "VideoRetriever::~VideoRetriever()" << std::endl;
    }

};

BaseRetriever* getRetriever(const std::string& retriever_type)
{
    if (retriever_type == "youla")
    {
        return new YoulaRetriever;
    }
    else if (retriever_type == "video")
    {
        return new VideoRetriever{};
    }
    return nullptr;
}

void search(BaseRetriever* retriever)
{
    retriever->retrieve(BaseRetriever::doc_t{});
    retriever->sort(BaseRetriever::docs_t{10, 0});
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <youla|video>" << std::endl;
        return 1;
    }

    //int foo();

    std::cout << sizeof(BaseRetriever) << std::endl;

    std::string retriever_type{argv[1]};

    BaseRetriever* retriever = getRetriever(retriever_type);
    search(retriever);

    delete retriever;
    return 0;
}

