package com.dong.dongblog.dao;

import com.dong.dongblog.model.Vote;
import com.dong.dongblog.model.VoteExample;
import java.util.List;
import org.apache.ibatis.annotations.Param;

public interface VoteDao {
    /**
     * This method was generated by MyBatis Generator.
     * This method corresponds to the database table vote
     *
     * @mbg.generated
     */
    long countByExample(VoteExample example);

    /**
     * This method was generated by MyBatis Generator.
     * This method corresponds to the database table vote
     *
     * @mbg.generated
     */
    int deleteByExample(VoteExample example);

    /**
     * This method was generated by MyBatis Generator.
     * This method corresponds to the database table vote
     *
     * @mbg.generated
     */
    int deleteByPrimaryKey(Long id);

    /**
     * This method was generated by MyBatis Generator.
     * This method corresponds to the database table vote
     *
     * @mbg.generated
     */
    int insert(Vote record);

    /**
     * This method was generated by MyBatis Generator.
     * This method corresponds to the database table vote
     *
     * @mbg.generated
     */
    int insertSelective(Vote record);

    /**
     * This method was generated by MyBatis Generator.
     * This method corresponds to the database table vote
     *
     * @mbg.generated
     */
    List<Vote> selectByExample(VoteExample example);

    /**
     * This method was generated by MyBatis Generator.
     * This method corresponds to the database table vote
     *
     * @mbg.generated
     */
    Vote selectByPrimaryKey(Long id);

    /**
     * This method was generated by MyBatis Generator.
     * This method corresponds to the database table vote
     *
     * @mbg.generated
     */
    int updateByExampleSelective(@Param("record") Vote record, @Param("example") VoteExample example);

    /**
     * This method was generated by MyBatis Generator.
     * This method corresponds to the database table vote
     *
     * @mbg.generated
     */
    int updateByExample(@Param("record") Vote record, @Param("example") VoteExample example);

    /**
     * This method was generated by MyBatis Generator.
     * This method corresponds to the database table vote
     *
     * @mbg.generated
     */
    int updateByPrimaryKeySelective(Vote record);

    /**
     * This method was generated by MyBatis Generator.
     * This method corresponds to the database table vote
     *
     * @mbg.generated
     */
    int updateByPrimaryKey(Vote record);
}