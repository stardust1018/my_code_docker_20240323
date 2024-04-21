use trait_10_3::Summary; // 引入trait方法
use trait_10_3::Tweet; // 引入数据结构定义
use trait_10_3::NewsArticle;

fn main() {
    println!("Hello, trait!");

    let tweet = Tweet {
        username: String::from("horse_ebooks"),
        content: String::from("of course, as you probably already know, people"),
        reply: false,
        retweet: false,
    };
    notify_detail(tweet);

    let news_article = NewsArticle {
        headline: String::from("melon love jiaojiao"),
        location: String::from("everywhere"),
        author: String::from("melon"),
        content: String::from("melon will go with jiaojiao forevery"),
    };
    notify_detail(news_article);
}

// impl Summary -- 表示实现了Summary trait的对象
fn notify(item: impl Summary) {
    println!("Breaking news! {}", item.summarize());
}

// trait bound
fn notify_detail<T: Summary>(item: T) {
    if item.filter_violence() != true {
        println!("Breaking news! {}", item.summarize());
    } else {
        println!("the news is violence!");
    }
    
}