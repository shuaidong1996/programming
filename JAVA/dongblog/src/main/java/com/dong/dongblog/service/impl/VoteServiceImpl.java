package com.dong.dongblog.service.impl;

import com.dong.dongblog.dao.VoteDao;
import com.dong.dongblog.dto.ResponseCommonDto;
import com.dong.dongblog.model.Vote;
import com.dong.dongblog.model.VoteExample;
import com.dong.dongblog.service.VoteService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class VoteServiceImpl implements VoteService {
    @Autowired
    private VoteDao voteDao;

    @Override
    public ResponseCommonDto vote(Long userId, Long blogId) {
        ResponseCommonDto responseCommonDto = new ResponseCommonDto();
        responseCommonDto.setSuccess(false);
        if(checkVote(userId, blogId)){
            responseCommonDto.setErrorMsg("已经投过票了");
            return responseCommonDto;
        }

        Vote vote = new Vote();
        vote.setUserId(userId);
        vote.setBlogId(blogId);
        voteDao.insert(vote);

        responseCommonDto.setSuccess(true);
        return responseCommonDto;
    }

    @Override
    public ResponseCommonDto cancelVote(Long userId, Long blogId) {
        ResponseCommonDto responseCommonDto = new ResponseCommonDto();
        responseCommonDto.setSuccess(false);
        if(!checkVote(userId, blogId)){
            responseCommonDto.setErrorMsg("没有投过票");
            return responseCommonDto;
        }

        VoteExample voteExample = new VoteExample();
        VoteExample.Criteria criteria = voteExample.createCriteria();
        criteria.andUserIdEqualTo(userId).andBlogIdEqualTo(blogId);
        voteDao.deleteByExample(voteExample);

        responseCommonDto.setSuccess(true);
        return responseCommonDto;
    }

    @Override
    public Boolean checkVote(Long userId, Long blogId) {
        VoteExample voteExample = new VoteExample();
        VoteExample.Criteria criteria = voteExample.createCriteria();
        criteria.andUserIdEqualTo(userId).andBlogIdEqualTo(blogId);
        List<Vote> votes = voteDao.selectByExample(voteExample);
        if(votes.size() == 0){
            return false;
        }
        return true;
    }
}
