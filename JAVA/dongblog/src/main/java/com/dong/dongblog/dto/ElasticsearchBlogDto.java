package com.dong.dongblog.dto;

import com.dong.dongblog.model.BlogWithBLOBs;
import org.springframework.data.elasticsearch.annotations.Document;

import java.io.Serializable;

/**
 * indexName索引名称 可以理解为数据库名 必须为小写 不然会报org.elasticsearch.indices.InvalidIndexNameException异常
 * type类型 可以理解为表名
 */
@Document(indexName = "dongblog", type = "blog")
public class ElasticsearchBlogDto extends BlogWithBLOBs implements Serializable {
}
