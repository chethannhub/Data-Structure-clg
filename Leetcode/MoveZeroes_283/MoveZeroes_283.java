package MoveZeroes_283;
class MoveZeroes_283 {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                for (int j = i; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                nums[n - 1] = 0;
                n--;
                i--;
            }
        }
    }

    public static void main(String[] args) {
        MoveZeroes_283 mz = new MoveZeroes_283();
        int[] nums = new int[]{0, 1, 0, 3, 12};
        mz.moveZeroes(nums);

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
    }
}