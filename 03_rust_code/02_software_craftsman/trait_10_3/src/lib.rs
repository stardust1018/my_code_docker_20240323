// 定义Summary trait，其中包含两个方法签名
pub trait Summary {
    fn summarize(&self) -> String;

    // 提供默认实现
    fn filter_violence(&self) -> bool {
        false
    }
}

pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

// 为NewsArticle结构体实现 Summary trait中定义的方法，其中filter_violence采用默认实现
impl Summary for NewsArticle {
    fn summarize(&self) -> String {
        format!("NewsArticle: {}, by {} ({})", self.headline, self.author, self.location)
    }
}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

// 为Tweet结构体实现 Summary trait中定义的方法
impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("Tweet: {}: {}", self.username, self.content)
    }

    fn filter_violence(&self) -> bool {
        true
    }
}